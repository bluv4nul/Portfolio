#include "task_list.h"
#include <stdio.h>

//функция добавления задачи
TaskNode* add_task(TaskNode* head, Task* new_task){
    TaskNode* node = malloc(sizeof(TaskNode));
    if(node == NULL){
        printf("ERROR: can't allocate memory (add_task)\n");
        return NULL;
    }
    node->task = new_task;
    node->next = NULL;
    if(head == NULL){
        return node;
    }
    else{
        TaskNode* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = node;
        return head;
    }
}
//функция удаления задачи
TaskNode* remove_task(TaskNode* head, int id){
    if(head == NULL){
        printf("ERROR: can't remove task\n");
        return NULL;
    }

    if(head->task->id == id){
        TaskNode* to_delete = head;
        head = head->next;
        free_task(to_delete->task);
        free(to_delete);
        return head;
    }

    TaskNode* prev = head;
    TaskNode* current = head->next;
    while(current!=NULL){
        if (current->task->id == id){
            prev->next=current->next;
            free_task(current->task);
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }
    return head;
}

//Освобождение всего списка
void free_task_list(TaskNode* head){
    TaskNode* current = head;
    while (current != NULL) {
        TaskNode* next = current->next;
        free_task(current->task);  
        free(current);             
        current = next;
    }
}

TaskNode* delete_all_tasks(TaskNode* head){
    if(head == NULL){
        printf("Передан пустой список!");
        return head;
    }

    while(head != NULL){
        TaskNode* to_delete = head;
        head = head->next;
        free_task(to_delete->task);
        free(to_delete);
    }
    return head;
}   