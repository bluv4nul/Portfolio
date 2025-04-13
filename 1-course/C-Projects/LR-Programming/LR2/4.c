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
    printf("\n");

    double *arr = (double*)malloc(size * sizeof(double));

    for(int i = 0; i < size;i ++)
    {
        printf("Введите %d элемент массива: ", i);
        scanf("%lf", (arr+i));
    }

    printf("\nМассив: ");
    for(int i = size-1; i >= 0; i--)
    {
        printf("%.2lf ", *(arr+i));
    }
    
    free(arr);
}