#include "task.h"
#include "task_list.h"
#ifndef CLI_HANDLER_H
#define CLI_HANDLER_H



int show_menu(void);
void print_tasks(TaskNode* head);
Task* input_new_task();
void cli_handler(TaskNode** head_ptr, const char* default_filename);

#endif
