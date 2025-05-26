/*
Напишите программу, которая запрашивает у пользователя размер массива целых чисел, 
динамически выделяет память под этот массив с помощью malloc, 
заполняет его квадратами чисел от 0 до size - 1, 
выводит массив на экран и освобождает память с помощью free.
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int size;
    printf("Введите размер массива: ");
    scanf("%d",&size);

    int *arr = (int *)malloc(sizeof(int)*size);
    for(int i = 0; i <= size - 1; i++){
        arr[i] = i*i;
    }
    for(int i = 0; i <= size - 1; i++){
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}