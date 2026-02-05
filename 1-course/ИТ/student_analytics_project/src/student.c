/**
 * @file student.c
 * @brief Реализация функций для работы с данными студентов.
 *
 * Этот файл содержит реализацию функций, объявленных в student.h,
 * для работы с данными студентов: загрузка из CSV, расчет статистики,
 * сортировка и сохранение отчетов. Используются библиотеки GSL для
 * статистических расчетов и libcurl для загрузки данных из интернета.
 *
 * @warning Вы должны внимательно изучить реализацию функций и комментарии,
 * чтобы понять принципы работы с внешними библиотеками и обработки данных.
 */

#include "../include/student.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <gsl/gsl_statistics.h>
#include <gsl/gsl_sort.h>
#include <curl/curl.h>

/**
 * @brief Структура для хранения данных, загруженных через libcurl.
 *
 * Эта вспомогательная структура используется для хранения данных,
 * загруженных из интернета с помощью libcurl.
 */
struct MemoryStruct {
    char *memory;   /**< Указатель на буфер с данными */
    size_t size;    /**< Размер буфера */
};

/**
 * @brief Функция обратного вызова для записи данных, полученных через libcurl.
 *
 * Эта функция вызывается libcurl при получении данных и записывает их в буфер.
 *
 * @param contents Указатель на полученные данные
 * @param size Размер одного элемента данных
 * @param nmemb Количество элементов данных
 * @param userp Указатель на пользовательские данные (структура MemoryStruct)
 * @return Общий размер обработанных данных
 */
static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;
    
    /* Перевыделяем память для буфера с учетом новых данных */
    char *ptr = realloc(mem->memory, mem->size + realsize + 1);
    if (ptr == NULL) {
        /* Ошибка выделения памяти */
        fprintf(stderr, "Ошибка: не удалось выделить память (realloc вернул NULL)\n");
        return 0;
    }
    
    mem->memory = ptr;
    /* Копируем новые данные в буфер */
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0; /* Добавляем завершающий нулевой символ */
    
    return realsize;
}

/**
 * @brief Удаляет начальные и конечные пробельные символы из строки.
 *
 * Функция удаляет пробелы, табуляции и другие пробельные символы
 * в начале и конце строки. Изменяет исходную строку.
 *
 * @param str Указатель на строку для обработки
 */
static void trim(char *str) {
    if (str == NULL) return;
    
    /* Удаляем пробельные символы в конце строки */
    char *end = str + strlen(str) - 1;
    while (end >= str && isspace((unsigned char)*end)) {
        *end = '\0';
        end--;
    }
    
    /* Удаляем пробельные символы в начале строки */
    char *start = str;
    while (*start && isspace((unsigned char)*start)) {
        start++;
    }
    
    /* Если были удалены символы в начале, сдвигаем строку */
    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }
}

int load_students_csv(const char *filename, Student *students, size_t max_students) {
    /**
     * Открываем файл для чтения. Если файл не существует или не может быть открыт,
     * возвращаем ошибку (-1).
     */
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Ошибка: не удалось открыть файл '%s'\n", filename);
        return -1;
    }
    
    /* Буфер для чтения строк из файла */
    char line[1024];
    size_t count = 0;
    
    /* Пропускаем заголовок CSV-файла */
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return 0; /* Файл пуст */
    }
    
    /* Читаем данные студентов построчно */
    while (count < max_students && fgets(line, sizeof(line), file)) {
        char *token;
        int field_index = 0;
        
        /* Инициализируем структуру студента */
        memset(&students[count], 0, sizeof(Student));
        
        /* Разбираем строку на поля, разделенные запятыми */
        token = strtok(line, ",");
        while (token != NULL && field_index <= MAX_SCORES + 1) {
            /* Удаляем лишние пробелы */
            trim(token);
            
            if (field_index == 0) {
                /* Первое поле - ID студента */
                strncpy(students[count].id, token, MAX_ID_LENGTH - 1);
                students[count].id[MAX_ID_LENGTH - 1] = '\0';
            } else if (field_index == 1) {
                /* Второе поле - имя студента */
                strncpy(students[count].name, token, MAX_NAME_LENGTH - 1);
                students[count].name[MAX_NAME_LENGTH - 1] = '\0';
            } else if (field_index > 1 && field_index - 2 < MAX_SCORES) {
                /* Последующие поля - оценки */
                students[count].scores[field_index - 2] = atof(token);
                students[count].num_scores = field_index - 1;
            }
            
            token = strtok(NULL, ",");
            field_index++;
        }
        
        /* Проверяем, что у студента есть хотя бы одна оценка */
        if (students[count].num_scores > 0) {
            count++;
        }
    }
    
    fclose(file);
    return count;
}

void calculate_statistics(Student *students, size_t count) {
    /* Для каждого студента вычисляем статистические показатели */
    for (size_t i = 0; i < count; i++) {
        Student *student = &students[i];
        
        /* Проверяем, что у студента есть оценки */
        if (student->num_scores <= 0) {
            student->average = 0.0;
            student->median = 0.0;
            student->std_deviation = 0.0;
            student->rating = 0.0;
            continue;
        }
        
        /* Создаем копию массива оценок для сортировки */
        double sorted_scores[MAX_SCORES];
        memcpy(sorted_scores, student->scores, student->num_scores * sizeof(double));
        
        /* Используем GSL для расчета статистических показателей */
        
        /* Среднее значение */
        student->average = gsl_stats_mean(student->scores, 1, student->num_scores);
        
        /* Сортируем оценки для расчета медианы */
        gsl_sort(sorted_scores, 1, student->num_scores);
        
        /* Медиана */
        student->median = gsl_stats_median_from_sorted_data(sorted_scores, 1, student->num_scores);
        
        /* Стандартное отклонение */
        student->std_deviation = gsl_stats_sd(student->scores, 1, student->num_scores);
        
        /* Рассчитываем рейтинг студента на основе статистических показателей */
        /* Формула: 0.5 * среднее + 0.3 * медиана + 0.2 * (10 - стандартное_отклонение) */
        /* Это поощряет высокие и стабильные оценки */
        double stability_factor = 10.0 - (student->std_deviation > 10.0 ? 10.0 : student->std_deviation);
        student->rating = 0.5 * student->average + 0.3 * student->median + 0.2 * stability_factor;
    }
}

bool sort_students(Student *students, size_t count, const char *sort_by) {
    if (count <= 1) {
        return true; /* Нечего сортировать */
    }
    
    /* Определяем критерий сортировки */
    int criterion;
    if (strcmp(sort_by, "average") == 0) {
        criterion = 0;
    } else if (strcmp(sort_by, "median") == 0) {
        criterion = 1;
    } else if (strcmp(sort_by, "rating") == 0) {
        criterion = 2;
    } else {
        fprintf(stderr, "Ошибка: неизвестный критерий сортировки '%s'\n", sort_by);
        return false;
    }
    
    /* Сортировка пузырьком по выбранному критерию */
    for (size_t i = 0; i < count - 1; i++) {
        for (size_t j = 0; j < count - i - 1; j++) {
            double val1, val2;
            
            /* Выбираем значения для сравнения в зависимости от критерия */
            switch (criterion) {
                case 0: /* average */
                    val1 = students[j].average;
                    val2 = students[j + 1].average;
                    break;
                case 1: /* median */
                    val1 = students[j].median;
                    val2 = students[j + 1].median;
                    break;
                case 2: /* rating */
                    val1 = students[j].rating;
                    val2 = students[j + 1].rating;
                    break;
                default:
                    val1 = val2 = 0.0;
                    break;
            }
            
            /* Если текущий элемент меньше следующего, меняем их местами */
            if (val1 < val2) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    
    return true;
}

bool save_report_csv(const char *filename, const Student *students, size_t count) {
    /* Открываем файл для записи */
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Ошибка: не удалось открыть файл '%s' для записи\n", filename);
        return false;
    }
    
    /* Записываем заголовок CSV-файла */
    fprintf(file, "ID,Name,NumScores,Average,Median,StdDeviation,Rating\n");
    
    /* Записываем данные каждого студента */
    for (size_t i = 0; i < count; i++) {
        const Student *student = &students[i];
        fprintf(file, "%s,%s,%d,%.2f,%.2f,%.2f,%.2f\n",
                student->id,
                student->name,
                student->num_scores,
                student->average,
                student->median,
                student->std_deviation,
                student->rating);
    }
    
    fclose(file);
    return true;
}

bool fetch_additional_data(const char *url, Student *students, size_t count) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;
    
    /* Инициализируем структуру для хранения данных */
    chunk.memory = malloc(1);
    chunk.size = 0;
    
    /* Инициализируем libcurl */
    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Ошибка: не удалось инициализировать libcurl\n");
        free(chunk.memory);
        return false;
    }
    
    /* Настраиваем параметры запроса */
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    
    /* Выполняем запрос */
    res = curl_easy_perform(curl);
    
    /* Проверяем результат */
    if (res != CURLE_OK) {
        fprintf(stderr, "Ошибка curl: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        free(chunk.memory);
        return false;
    }
    
    /* Обрабатываем полученные данные */
    /* Здесь должен быть код для разбора полученных данных и обновления информации о студентах */
    /* Для простоты примера просто выводим количество полученных байт */
    printf("Получено %lu байт данных\n", (unsigned long)chunk.size);
    
    /* Освобождаем ресурсы */
    curl_easy_cleanup(curl);
    free(chunk.memory);
    
    return true;
}

void print_student(const Student *student) {
    printf("ID: %s\n", student->id);
    printf("Имя: %s\n", student->name);
    printf("Количество оценок: %d\n", student->num_scores);
    
    printf("Оценки: ");
    for (int i = 0; i < student->num_scores; i++) {
        printf("%.1f ", student->scores[i]);
    }
    printf("\n");
    
    printf("Средний балл: %.2f\n", student->average);
    printf("Медиана: %.2f\n", student->median);
    printf("Стандартное отклонение: %.2f\n", student->std_deviation);
    printf("Рейтинг: %.2f\n", student->rating);
    printf("\n");
}

bool generate_test_data(const char *filename, size_t num_students) {
    /* Открываем файл для записи */
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Ошибка: не удалось открыть файл '%s' для записи\n", filename);
        return false;
    }
    
    /* Инициализируем генератор случайных чисел */
    srand(time(NULL));
    
    /* Записываем заголовок CSV-файла */
    fprintf(file, "ID,Name,Score1,Score2,Score3,Score4,Score5\n");
    
    /* Генерируем данные для каждого студента */
    for (size_t i = 0; i < num_students; i++) {
        /* Генерируем ID студента */
        fprintf(file, "ST%04zu,", i + 1);
        
        /* Генерируем имя студента */
        const char *first_names[] = {"Иван", "Петр", "Алексей", "Михаил", "Сергей", "Анна", "Мария", "Елена", "Ольга", "Татьяна"};
        const char *last_names[] = {"Иванов", "Петров", "Сидоров", "Смирнов", "Кузнецов", "Иванова", "Петрова", "Сидорова", "Смирнова", "Кузнецова"};
        
        int first_idx = rand() % 10;
        int last_idx = rand() % 10;
        
        fprintf(file, "%s %s", first_names[first_idx], last_names[last_idx]);
        
        /* Генерируем оценки */
        for (int j = 0; j < 5; j++) {
            /* Генерируем оценку от 2.0 до 5.0 с шагом 0.5 */
            double score = 2.0 + (rand() % 7) * 0.5;
            fprintf(file, ",%.1f", score);
        }
        
        fprintf(file, "\n");
    }
    
    fclose(file);
    return true;
}
