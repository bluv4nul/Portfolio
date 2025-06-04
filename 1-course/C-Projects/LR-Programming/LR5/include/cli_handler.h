#ifndef CLI_HANDLER_H
#define CLI_HANDLER_H

#include "task.h"
#include "task_list.h"

//Выводит меню
int show_menu(void);

//Выводит задачи
void print_tasks(TaskNode* head);

//Введение новой задачи
Task* input_new_task();

//Управление всем вместе
void cli_handler(TaskNode** head_ptr, const char* default_filename);

#endif
