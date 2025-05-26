#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "task_list.h"
#include <stdbool.h>

// Проверка существования файла
bool file_exists(const char* filename);

// Создание нового пустого файла
bool create_new_file(const char* filename);

// Загрузка задач из файла
TaskNode* load_tasks_from_file(const char* filename);

// Сохранение списка задач в файл
bool save_tasks_to_file(const char* filename, TaskNode* head);

// Автосохранение — вызывает сохранение после каждого изменения
bool autosave(TaskNode* head, const char* autosave_filename);

#endif // FILE_MANAGER_H
