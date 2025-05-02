#include <math.h>
#include <stdio.h>
#include <Windows.h>

int cycle_fact(int n){
    int res = 1;
    for(int i = 2; i <= n; i++){
        res *= i;
    }
    return res;
}

int recursion_fact (int n){
    if (n == 1){return 1;} 
    return recursion_fact(n-1)*n;
}

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    printf("Факториал циклом: %d\n", cycle_fact(12));
    printf("Факториал рекурсией: %d\n", recursion_fact(12));
};