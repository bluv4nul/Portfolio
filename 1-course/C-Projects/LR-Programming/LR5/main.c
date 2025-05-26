#include <stdio.h>
#include "task_list.h"   // для TaskNode, free_task_list
#include "cli_handler.h" // для cli_handler
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    TaskNode* head = NULL;          // Изначально список пуст
    const char* filename = "tasks.csv"; // Имя файла для хранения задач

    cli_handler(&head, filename);   // Запускаем интерфейс

    free_task_list(head);           // Освобождаем память перед выходом
    return 0;
}
