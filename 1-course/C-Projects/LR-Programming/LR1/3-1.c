#include <math.h>
#include <stdio.h>
#include <Windows.h>

int main(void)
{
    
    SetConsoleOutputCP(CP_UTF8);
    int length;

    printf("Введите длинну вектора: ");
    scanf("%d", &length);
    int vector[length] = {};

    for(int i = 0; i < length; i++)
    {
        printf("Введите %d число вектора: ", i);
        scanf("%d", &vector[i]);
        vector[i] = vector[i]*vector[i];
    }

    printf("Полученный вектор ( ");

    for (int i = 0; i < length; i++)
    {
        printf("%d ", vector[i]);
    }

    printf(")");
}