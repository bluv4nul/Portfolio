#include "file_manager.h"
#include "task_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Проверка существования файла
bool file_exists(const char* filename){
    FILE *file = fopen(filename, "r");
    if(file == NULL){
        return false;
    }
    else{
        fclose(file);
        return true;
    }
}

// Создание нового пустого файла
bool create_new_file(const char* filename){
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        printf("ERROR: can`t create file%s\n",filename);
        return false;
    }
    fclose(file);
    return true;
}

// Загрузка задач из файла
TaskNode* load_tasks_from_file(const char* filename){
    FILE *file = fopen(filename, "r");
    if(file == NULL){
        printf("ERROR: can`t open file %s\n", filename);
        return NULL;
    }

    TaskNode *head = NULL;
    char buffer[1024];
    char *token;
    while(fgets(buffer,sizeof(buffer),file) != NULL){
        // Убираем перенос строки в конце
        buffer[strcspn(buffer, "\n")] = 0;

        //парсим id
        token = strtok(buffer, ",");
        if (token == NULL) continue;
        int id = atoi(token);
        
        // Парсим description
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        char* description = token;

        // Парсим дату и время
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        int year = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        int mon = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        int day = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        int hour = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        int min = atoi(token);

        // Парсим статус
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        int status_int = atoi(token);

        struct tm due_date = {0};
        due_date.tm_year = year - 1900; // tm_year — годы с 1900
        due_date.tm_mon = mon-1;
        due_date.tm_mday = day;
        due_date.tm_hour = hour;
        due_date.tm_min = min;

        Task* task = create_task(id, description, due_date, (Status)status_int);
        if(task == NULL){
            printf("ERROR: can`t create task");
            continue;
        }

        head = add_task(head, task);
    }
 
    fclose(file);
    return head;
}

// Сохранение списка задач в файл
bool save_tasks_to_file(const char* filename, TaskNode* head){
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        printf("ERROR: can`t open file");
        return false;
    }

    TaskNode* current = head;
    while(current != 0){
        Task *task = current->task;
        // Запишем в файл: id, описание, год, месяц, день, час, минута, статус
        // Формат записи: id,description,year,month,day,hour,minute,status\n
        // Чтобы избежать проблем с запятыми в описании, можно оборачивать строку в кавычки или использовать другой разделитель.
        fprintf(file, "%d,\"%s\",%d,%d,%d,%d,%d,%d\n",
                task->id,
                task->description,
                task->due_date.tm_year + 1900,
                task->due_date.tm_mon + 1,
                task->due_date.tm_mday,
                task->due_date.tm_hour,
                task->due_date.tm_min,
                task->status);
        current = current->next;
    }

    fclose(file);
    return true;
}

// Автосохранение — вызывает сохранение после каждого изменения
bool autosave(TaskNode* head, const char* autosave_filename) {
    if (autosave_filename == NULL) {
        printf("ERROR: autosave filename is NULL\n");
        return false;
    }
    return save_tasks_to_file(autosave_filename, head);
}