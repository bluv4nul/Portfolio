#include <math.h>
#include <stdio.h>
#include <Windows.h>

int cycle_factorial(int n){
    int res = 1;
    for(int i = 2; i <= n; i++){
        res *= i;
    }
    return res;
}

int recursion_factorial (int n){
    if (n == 1){return 1;} 
    return recursion_factorial(n-1)*n;
}

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    printf("Факториал циклом: %d\n", cycle_factorial(12));
    printf("Факториал рекурсией: %d\n", recursion_factorial(12));
};