/**
 * @file main.c
 * @brief Главный модуль программы анализа успеваемости студентов.
 *
 * Этот файл содержит функцию main и логику обработки аргументов командной строки.
 * Программа позволяет загружать данные студентов из CSV-файла, рассчитывать
 * статистические показатели, сортировать студентов по различным критериям и
 * сохранять результаты в виде отчетов.
 *
 * @warning Вы должны внимательно изучить структуру программы и комментарии,
 * чтобы понять принципы организации консольных приложений и обработки аргументов
 * командной строки.
 */

#include "../include/student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief Максимальное количество студентов, которое может обработать программа.
 *
 * Это ограничение введено для предотвращения чрезмерного использования памяти.
 * При необходимости обработки большего количества студентов следует увеличить
 * это значение или реализовать динамическое выделение памяти.
 */
#define MAX_STUDENTS 1000

/**
 * @brief Выводит справку по использованию программы.
 *
 * Функция выводит информацию о доступных командах и аргументах программы.
 *
 * @param program_name Имя программы (обычно argv[0])
 */
void print_usage(const char *program_name) {
    printf("Использование: %s <команда> [аргументы]\n\n", program_name);
    printf("Доступные команды:\n");
    printf("  load <файл.csv>                     - Загрузить данные студентов из CSV-файла\n");
    printf("  stats <файл.csv>                    - Рассчитать статистику и вывести результаты\n");
    printf("  sort <файл.csv> <критерий> <отчет>  - Сортировать студентов и сохранить отчет\n");
    printf("  fetch <файл.csv> <url> <отчет>      - Загрузить дополнительные данные и сохранить отчет\n");
    printf("  generate <файл.csv> <количество>    - Сгенерировать тестовые данные\n\n");
    printf("Критерии сортировки: average (средний балл), median (медиана), rating (рейтинг)\n");
}

/**
 * @brief Главная функция программы.
 *
 * Обрабатывает аргументы командной строки и вызывает соответствующие функции
 * для выполнения запрошенных операций.
 *
 * @param argc Количество аргументов командной строки
 * @param argv Массив аргументов командной строки
 * @return Код завершения программы (0 - успешно, не 0 - ошибка)
 */
int main(int argc, char *argv[]) {
    /* Проверяем, достаточно ли аргументов */
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    /* Определяем команду */
    const char *command = argv[1];

    /* Массив для хранения данных студентов */
    Student students[MAX_STUDENTS];
    int count;

    /* Обрабатываем команду */
    if (strcmp(command, "load") == 0) {
        /* Команда load: загрузка данных из CSV-файла */
        if (argc < 3) {
            fprintf(stderr, "Ошибка: не указан файл CSV\n");
            print_usage(argv[0]);
            return 1;
        }

        const char *filename = argv[2];
        count = load_students_csv(filename, students, MAX_STUDENTS);

        if (count < 0) {
            fprintf(stderr, "Ошибка при загрузке файла '%s'\n", filename);
            return 1;
        }

        printf("Загружено %d студентов из файла '%s'\n", count, filename);
        
        /* Выводим данные первых 5 студентов (или меньше, если их меньше 5) */
        printf("\nПервые %d студентов:\n", count < 5 ? count : 5);
        for (int i = 0; i < count && i < 5; i++) {
            print_student(&students[i]);
        }

    } else if (strcmp(command, "stats") == 0) {
        /* Команда stats: расчет статистики */
        if (argc < 3) {
            fprintf(stderr, "Ошибка: не указан файл CSV\n");
            print_usage(argv[0]);
            return 1;
        }

        const char *filename = argv[2];
        count = load_students_csv(filename, students, MAX_STUDENTS);

        if (count < 0) {
            fprintf(stderr, "Ошибка при загрузке файла '%s'\n", filename);
            return 1;
        }

        /* Рассчитываем статистические показатели */
        calculate_statistics(students, count);

        printf("Рассчитана статистика для %d студентов из файла '%s'\n", count, filename);
        
        /* Выводим статистику для всех студентов */
        for (int i = 0; i < count; i++) {
            print_student(&students[i]);
        }

    } else if (strcmp(command, "sort") == 0) {
        /* Команда sort: сортировка студентов и сохранение отчета */
        if (argc < 5) {
            fprintf(stderr, "Ошибка: недостаточно аргументов для команды sort\n");
            print_usage(argv[0]);
            return 1;
        }

        const char *filename = argv[2];
        const char *sort_by = argv[3];
        const char *report_file = argv[4];

        count = load_students_csv(filename, students, MAX_STUDENTS);

        if (count < 0) {
            fprintf(stderr, "Ошибка при загрузке файла '%s'\n", filename);
            return 1;
        }

        /* Рассчитываем статистические показатели */
        calculate_statistics(students, count);

        /* Сортируем студентов по указанному критерию */
        if (!sort_students(students, count, sort_by)) {
            fprintf(stderr, "Ошибка при сортировке студентов\n");
            return 1;
        }

        /* Сохраняем отчет */
        if (!save_report_csv(report_file, students, count)) {
            fprintf(stderr, "Ошибка при сохранении отчета в файл '%s'\n", report_file);
            return 1;
        }

        printf("Студенты отсортированы по критерию '%s' и сохранены в файл '%s'\n", sort_by, report_file);

    } else if (strcmp(command, "fetch") == 0) {
        /* Команда fetch: загрузка дополнительных данных из интернета */
        if (argc < 5) {
            fprintf(stderr, "Ошибка: недостаточно аргументов для команды fetch\n");
            print_usage(argv[0]);
            return 1;
        }

        const char *filename = argv[2];
        const char *url = argv[3];
        const char *report_file = argv[4];

        count = load_students_csv(filename, students, MAX_STUDENTS);

        if (count < 0) {
            fprintf(stderr, "Ошибка при загрузке файла '%s'\n", filename);
            return 1;
        }

        /* Загружаем дополнительные данные */
        if (!fetch_additional_data(url, students, count)) {
            fprintf(stderr, "Ошибка при загрузке данных с URL '%s'\n", url);
            return 1;
        }

        /* Рассчитываем статистические показатели */
        calculate_statistics(students, count);

        /* Сохраняем отчет */
        if (!save_report_csv(report_file, students, count)) {
            fprintf(stderr, "Ошибка при сохранении отчета в файл '%s'\n", report_file);
            return 1;
        }

        printf("Дополнительные данные загружены с URL '%s' и сохранены в файл '%s'\n", url, report_file);

    } else if (strcmp(command, "generate") == 0) {
        /* Команда generate: генерация тестовых данных */
        if (argc < 4) {
            fprintf(stderr, "Ошибка: недостаточно аргументов для команды generate\n");
            print_usage(argv[0]);
            return 1;
        }

        const char *filename = argv[2];
        int num_students = atoi(argv[3]);

        if (num_students <= 0 || num_students > 1000) {
            fprintf(stderr, "Ошибка: количество студентов должно быть от 1 до 1000\n");
            return 1;
        }

        if (!generate_test_data(filename, num_students)) {
            fprintf(stderr, "Ошибка при генерации тестовых данных в файл '%s'\n", filename);
            return 1;
        }

        printf("Сгенерированы тестовые данные для %d студентов в файл '%s'\n", num_students, filename);

    } else {
        /* Неизвестная команда */
        fprintf(stderr, "Ошибка: неизвестная команда '%s'\n", command);
        print_usage(argv[0]);
        return 1;
    }

    return 0;
}
