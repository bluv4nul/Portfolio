#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

void swap(int *arr, int n){
    for(int i = 0; i < n; i+=2){
        arr[i] ^= arr[i+1];
        arr[i+1] ^= arr[i];
        arr[i] ^= arr[i+1];
    }
}

void print_array(int *arr, int n){
    printf("Массив: [");
    for(int i = 0; i < n; i++){
        if(i == n-1){
            printf("%d]",arr[i]);
            break;
        }
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    int n = 12;
    int *arr = (int *)malloc(sizeof(int)*n);

    for(int i = 0; i < n; i++){
        printf("Введите %d эелемент массива: ",i+1);
        scanf("%d",(arr+i));
    }
    printf("\n");
    
    print_array(arr, n);
    swap(arr, n);
    print_array(arr, n);
    free(arr);
};