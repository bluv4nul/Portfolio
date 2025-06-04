#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Task* create_task(int id, const char* desc, struct tm due_date, Status status){
    //выделаяем память под задачу
    Task *task = malloc(sizeof(Task));
    if (task == NULL) {
    printf("ERROR: can't allocate memory (create_task)\n");
    return NULL;}
    
    //выделяем память под описание
    task->description = malloc(strlen(desc)+1);
    if (task->description == NULL) {
    printf("ERROR: can't allocate memory(create_task -> descriptrion)\n");
    free(task);
    return NULL;}
    
    //Заполняем все данные
    strcpy(task->description, desc);
    task->due_date = due_date;
    task->id = id;
    task->status = status;

    return task;
}

void free_task(Task* task) {
    if (task == NULL) {
        return; // Нечего освобождать
    }

    if (task->description != NULL) {
        free(task->description); // Освобождаем описание
    }

    free(task); // Освобождаем саму структуру задачи
}
