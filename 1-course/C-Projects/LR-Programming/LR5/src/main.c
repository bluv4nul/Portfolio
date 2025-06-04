#include "cli_handler.h"
#include "file_manager.h"
#include "task_list.h"
#include "task.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>



int main(void){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const char* default_file_name = "tasks.csv";

    TaskNode* head = NULL;  // Изначально список пуст
    cli_handler(&head, default_file_name);     // Запускаем интерфейс
    free_task_list(head);   // Освобождаем память перед выходом
    return 0;
}