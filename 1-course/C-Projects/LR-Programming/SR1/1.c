#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);

    int n;
    float s;

    printf("Введите размерность массива N: ");
    scanf("%d",&n);

    float *arr = (float *)malloc(n*sizeof(float));
    
    for(int i = 0; i < n; i++)
    {
        printf("Введите %d элемент массива: ", i);
        scanf("%f", (arr+i));
    }
    
    for(int i = 0; i < n; i++)
    {
        s+=*(arr+i);
    }
    s/=n;
    printf("Среднее арифметическое: %.2f", s);
    
    free(arr);
}