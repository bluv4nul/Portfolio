#include <stdio.h>
#include <Windows.h>

// Функция для проверки пересечения отрезков и нахождения общей части
void find_intersection(float a1, float b1, float a2, float b2) {
    float start = (a1 > a2) ? a1 : a2;  // max(a1, a2)
    float end = (b1 < b2) ? b1 : b2;     // min(b1, b2)

    if (start <= end) {
        printf("Отрезки пересекаются на интервале: [%.2f, %.2f]\n", start, end);
    } else {
        printf("Отрезки не пересекаются.\n");
    }
}

int main() {
    float a1, b1, a2, b2;
    SetConsoleOutputCP(CP_UTF8);

    printf("Введите координаты первого отрезка (a1 b1): ");
    scanf("%f %f", &a1, &b1);

    printf("Введите координаты второго отрезка (a2 b2): ");
    scanf("%f %f", &a2, &b2);

    find_intersection(a1, b1, a2, b2);

    return 0;
}