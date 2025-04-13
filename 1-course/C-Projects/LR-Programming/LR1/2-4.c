#include <math.h>
#include <stdio.h>
#include <Windows.h>

int sum_of_digits(int n)
{
    int res = 0;
    while(n>0){
        res += n%10;
        n/=10;
    }
    return res;
}

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    
    int n = 999;
    while(sum_of_digits(n)>10)
    {
        printf("Введите трехзначное число: ");
        scanf("%d", &n);
        printf("Сумма цифр числа: %d\n",sum_of_digits(n));
        if(n>999 || n < 100)
        {
            printf("Введено не трехзначное число!");
            return 0;
        }   
    }
}