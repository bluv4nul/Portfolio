#include <math.h>
#include <stdio.h>
#include <Windows.h>

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);

    int n;
    
    printf("Введите количество элементов массива: ");
    scanf("%d", &n);
    
    int X[n];
    
    printf("Введите %d элементов массива:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }
    
    for (int i = 0; i < n / 2; i++) {
        X[i] ^= X[n-1-i];
        X[n-1-i] ^= X[i];
        X[i] ^= X[n-1-i];
    }
    
    printf("Массив после разворота:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", X[i]);
    }
    printf("\n");
    
    return 0;
}