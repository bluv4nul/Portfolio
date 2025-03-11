#include <math.h>
#include <stdio.h>
#include <Windows.h>

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);

    int m;
    printf("Введите число m:\t");
    scanf("%d",m);

    int n0 = 1; int n1 = 1; int n2 = 1; int n3 = 0;

    while(n3 <= m)
    {
        n3 = n0 + n1;
        printf("%d",n3);
        n0 = n1; n1 = n2; n2 = n3;
    }
}