#include <stdio.h>
#include <windows.h>

int main(void)
{

SetConsoleOutputCP(CP_UTF8);
int arr[3][3]= {
    {12,22,13},
    {47,52,61},
    {7,80,19}
};

int sum_glavn = 0;
int sum_poboch = 0;

for(int i = 0; i <= 2; i++)
{
        sum_glavn += arr[i][i];
        sum_poboch += arr[i][2-i];
}
printf("Сумма эл. главной диагонали: %d\n",sum_glavn);
printf("Сумма эл. побочной диагонали: %d",sum_poboch);
}