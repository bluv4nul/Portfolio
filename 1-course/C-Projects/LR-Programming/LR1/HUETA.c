#include <math.h>
#include <stdio.h>
#include <Windows.h>

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);

    int arr[] = {42, 17, 89, 5, 23, 56, 34, 72, 11, 63, 28, 95, 50, 7, 39};
    int min;
    int index;
    int temp;
    int lentgh = sizeof(arr)/sizeof(int);

    printf("\nИсходная матрица: \n");

    for (int i = 0; i < lentgh; i++)
    {
        printf("%d ", arr[i]);
    }
    

    for (int i = 0; i < lentgh; i++)
    {
        min = arr[i];
        for (int j = i+1; j < lentgh; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = min;
        arr[index] = temp;
    }
    
    printf("\nПолученная матрица: \n");
    for(int i = 0; i < lentgh; i++)
    {
        printf("%d ", arr[i]);
    }
}