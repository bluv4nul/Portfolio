#include <math.h>
#include <stdio.h>
#include <Windows.h>

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);

    int length;

    printf("Введите длинну массива: ");
    scanf("%d", &length);

    int arr[length] = {};
    int t = 0;

    for(int i = length-1; i > -1; i--)
    {
        printf("Введите %d элемент массива: ", t);
        scanf("%d", &arr[i]);
        t++;
    }

    printf("Получившийся массив: [ ");
    for(int i = 0; i < length; i ++)
    {
        printf("%d ", arr[i]);
    }
    printf("]");

    
}