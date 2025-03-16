#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <math.h>

int main(void)
{
    int *a = (int *)malloc(sizeof(int));
    int *b = (int *)malloc(sizeof(int));
    int *res = (int *)malloc(sizeof(int));
    SetConsoleOutputCP(CP_UTF8);
    printf("Введите первое число: ");
    scanf("%d", a);
    printf("Введите второе число: ");
    scanf("%d", b);
    *res = *a + *b;
    printf("Результат: %d", *res);
    free(a);
    free(b);
    free(res);
}