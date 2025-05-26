/*
Напишите функцию calculate_stats, 
которая принимает массив целых чисел int arr[] и его размер int size. 
Функция должна вычислить и вернуть через указатели минимальное значение, 
максимальное значение и среднее арифметическое (тип double) элементов массива.
*/
#include <stdio.h>

void calculate_stats(int arr[], int size, int* min_val, int* max_val, double* avg_val) {
    *min_val = arr[0];
    *max_val = arr[0];
    *avg_val = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] < *min_val) *min_val = arr[i];
        if(arr[i] > *max_val) *max_val = arr[i];
        *avg_val+=arr[i];
    }
    *avg_val/=size;
}

// Пример использования (не обязательно для ответа)
int main() {
    int numbers[] = {5, 2, 9, 1, 5, 6, 8, 3, 7, 4};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int min_result, max_result;
    double avg_result;

    calculate_stats(numbers, size, &min_result, &max_result, &avg_result);

    printf("Минимум: %d\n", min_result);
    printf("Максимум: %d\n", max_result);
    printf("Среднее: %.2f\n", avg_result);

    return 0;
}