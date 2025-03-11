#include <stdio.h>
#include <math.h>

#define x_start 0     // Начальное значение x
#define x_end 10      // Конечное значение x
#define step 1        // Шаг
#define m_count 5        // Количество значений m

// Функция для расчёта y
double calc_y(double m, double x) {
    return 2 * m * sqrt(pow(1 + pow(m, 2) - pow(x, 2), 2) + 4 * pow(x, 2));
}

int main() {
    double m_values[m_count] = {1, 2, 3, 4, 5}; // Массив значений m
    int x_steps = ((x_end - x_start) / step) + 1; // Количество шагов по x

    // Заголовок таблицы
    printf("x\t");
    for (int i = 0; i < m_count; i++) {
        printf("y(m=%.1f)\t", m_values[i]);
    }
    printf("\n");

    // Расчёт и вывод значений
    for (int step_index = 0; step_index < x_steps; step_index++) {
        double x = x_start + step_index * step;
        printf("%.2f\t", x);

        for (int i = 0; i <= m_count-1; i++) {
            double y = calc_y(m_values[i], x);
            printf("%.6f\t", y);
        }

        printf("\n");
    }
}
