#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);

    int *a = (int *)malloc(sizeof(int));
    int *b = (int *)malloc(sizeof(int));

    printf("Введите первое число: ");
    scanf("%d", a);
    printf("Введите второе число: ");
    scanf("%d", b);

    if (*a > *b)
    {
        printf("Максимальное - a = %d", *a);
    }
    else
    {
        printf("Максимальное - b = %d", *b);
    }
    
    free(a);
    free(b);
}