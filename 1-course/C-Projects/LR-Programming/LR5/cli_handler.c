#include <stdio.h>
#include <string.h>
#include "cli_handler.h"
#include "task_list.h"
#include "file_manager.h"

// Вывод списка задач (без изменений)
void print_tasks(TaskNode* head) {
    if (head == NULL) {
        printf("Список задач пуст.\n");
        return;
    }

    TaskNode* current = head;
    while (current != NULL) {
        Task* task = current->task;
        printf("ID: %d\n", task->id);
        printf("Описание: %s\n", task->description);
        printf("Срок: %04d-%02d-%02d %02d:%02d\n",
               task->due_date.tm_year + 1900,
               task->due_date.tm_mon + 1,
               task->due_date.tm_mday,
               task->due_date.tm_hour,
               task->due_date.tm_min);

        switch (task->status) {
            case TODO: printf("Статус: TODO\n"); break;
            case IN_PROGRESS: printf("Статус: В процессе\n"); break;
            case DONE: printf("Статус: Сделано\n"); break;
            case OVERDUE: printf("Статус: Просрочено\n"); break;
            default: printf("Статус: Неизвестен\n");
        }
        printf("----------------------\n");
        current = current->next;
    }
}

// Ввод новой задачи (без изменений)
Task* input_new_task() {
    int id, year, mon, day, hour, min, status;
    char description[256];

    printf("Введите ID задачи: ");
    scanf("%d", &id);
    getchar();  // убрать остаток из буфера после scanf

    printf("Введите описание задачи (до 255 символов): ");
    fgets(description, sizeof(description), stdin);
    description[strcspn(description, "\n")] = 0;  // убрать \n

    printf("Введите дату выполнения задачи (год месяц день): ");
    scanf("%d %d %d", &year, &mon, &day);

    printf("Введите время выполнения задачи (часы минуты): ");
    scanf("%d %d", &hour, &min);

    printf("Введите статус задачи (0 - TODO, 1 - IN_PROGRESS, 2 - DONE, 3 - OVERDUE): ");
    scanf("%d", &status);
    getchar();

    struct tm due_date = {0};
    due_date.tm_year = year - 1900;
    due_date.tm_mon = mon - 1;
    due_date.tm_mday = day;
    due_date.tm_hour = hour;
    due_date.tm_min = min;

    return create_task(id, description, due_date, (Status)status);
}

// Отображение меню (без изменений)
int show_menu(void) {
    int choice;
    printf("\nВыберите действие:\n");
    printf("1. Создать новый список задач\n");
    printf("2. Открыть существующий список задач\n");
    printf("3. Просмотреть задачи\n");
    printf("4. Добавить задачу\n");
    printf("5. Удалить задачу\n");
    printf("6. Сохранить задачи\n");
    printf("7. Выход\n");
    printf("Введите номер действия: ");
    scanf("%d", &choice);
    getchar(); // убрать \n после scanf
    return choice;
}

// Новый обработчик CLI с запросом имени файла при загрузке/сохранении
void cli_handler(TaskNode** head_ptr, const char* default_filename) {
    int running = 1;
    char filename[256];
    strncpy(filename, default_filename, sizeof(filename));
    filename[sizeof(filename) - 1] = '\0';

    while (running) {
        int choice = show_menu();
        switch (choice) {
            case 1:
                // Создать новый список задач
                free_task_list(*head_ptr);
                *head_ptr = NULL;
                create_new_file(filename);
                printf("Новый список задач создан (%s).\n", filename);
                break;
            case 2: {
                // Открыть существующий список задач
                printf("Введите имя файла для загрузки (Enter для %s): ", filename);
                char input[256];
                if (fgets(input, sizeof(input), stdin)) {
                    if (input[0] != '\n') {
                        input[strcspn(input, "\n")] = 0;
                        strncpy(filename, input, sizeof(filename));
                        filename[sizeof(filename) - 1] = '\0';
                    }
                }
                free_task_list(*head_ptr);
                *head_ptr = load_tasks_from_file(filename);
                if (*head_ptr != NULL) {
                    printf("Задачи загружены из файла %s.\n", filename);
                } else {
                    printf("Файл пуст или не найден: %s\n", filename);
                }
                break;
            }
            case 3:
                // Просмотреть задачи
                print_tasks(*head_ptr);
                break;
            case 4: {
                // Добавить задачу
                Task* new_task = input_new_task();
                if (new_task != NULL) {
                    *head_ptr = add_task(*head_ptr, new_task);
                    printf("Задача добавлена.\n");
                } else {
                    printf("Ошибка при создании задачи.\n");
                }
                break;
            }
            case 5: {
                // Удалить задачу
                int id;
                printf("Введите ID задачи для удаления: ");
                scanf("%d", &id);
                getchar();
                *head_ptr = remove_task(*head_ptr, id);
                printf("Задача удалена (если ID был найден).\n");
                break;
            }
            case 6: {
                // Сохранить задачи
                printf("Введите имя файла для сохранения (Enter для %s): ", filename);
                char input[256];
                if (fgets(input, sizeof(input), stdin)) {
                    if (input[0] != '\n') {
                        input[strcspn(input, "\n")] = 0;
                        strncpy(filename, input, sizeof(filename));
                        filename[sizeof(filename) - 1] = '\0';
                    }
                }
                if (save_tasks_to_file(filename, *head_ptr)) {
                    printf("Задачи сохранены в файл %s.\n", filename);
                } else {
                    printf("Ошибка при сохранении файла %s.\n", filename);
                }
                break;
            }
            case 7:
                // Выход
                running = 0;
                printf("Выход из программы.\n");
                break;
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    }
}
