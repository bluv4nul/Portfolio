#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);

    
    int size;
    printf("Введите размер будущего массива: ");
    scanf("%d", &size);

    double *arr = (double*)malloc(size * sizeof(double));

    double *ptr = arr;
    for(int i = 0; i < size;i ++)
    {
        printf("Введите %d элемент массива: ", i);
        scanf("%lf", ptr);
        ptr++;
    }

    ptr = arr;
    printf("Массив: ");
    for(int i = 0; i < size; i++)
    {
        printf("%.2lf ", *ptr);
        ptr++;
    }
    
    free(arr);
    free(ptr);
}