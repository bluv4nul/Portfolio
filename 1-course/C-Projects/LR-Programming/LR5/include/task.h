    #ifndef TASK_H
    #define TASK_H

    #include <time.h>

    //Статус задачи
    typedef enum {
        TODO,
        IN_PROGRESS,
        DONE,
        OVERDUE
    } Status;

    //Структура для определения задачи: Id, описание, дата, статус
    typedef struct {
        int id;
        char *description;
        struct tm due_date;
        Status status;
    } Task;

    //Создание задачи
    Task* create_task(int id, const char* desc, struct tm due_date, Status status);

    //Освобождение задачи
    void free_task(Task* task);

    #endif // TASK_H