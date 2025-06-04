#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "task_list.h"
#include <stdbool.h>

// Проверка существования файла
bool file_exists(const char* filename);

// Загрузка задач из файла
TaskNode* load_tasks_from_file(const char* filename);

// Сохранение списка задач в файл
bool save_tasks_to_file(const char* filename, TaskNode* head);

//Выводит названия всех файлов в папке
void list_files_in_data_folder();

#endif // FILE_MANAGER_H
