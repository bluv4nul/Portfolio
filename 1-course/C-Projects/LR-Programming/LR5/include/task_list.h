#ifndef TASK_LIST_H
#define TASK_LIST_H

#include "task.h"
#include <stdlib.h>

typedef struct TaskNode
{
    Task *task;
    struct TaskNode *next;
} TaskNode;

//функция добавления задачи
TaskNode* add_task(TaskNode* head, Task* new_task);
//функция удаления задачи
TaskNode* remove_task(TaskNode* head, int id);
//Освобождение всего списка
void free_task_list(TaskNode* head);
//Удалить все задачи
TaskNode* delete_all_tasks(TaskNode* head);

#endif // TASK_LIST_H