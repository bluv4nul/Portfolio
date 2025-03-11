#include <math.h>
#include <stdio.h>
#include <Windows.h>

int P(int n)
{
    if(n == 1 || n == 0 || n == 2)
    {
        return 1;
    }
    return P(n-2) + P(n-3);
}

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);

    int m;
    printf("Введите число m: ");
    scanf("%d", &m);

    printf("Последовательность чисел Падована: ");
    for(int i = 0; P(i) <= m; i++){
        printf("%d ",P(i));
    }
}