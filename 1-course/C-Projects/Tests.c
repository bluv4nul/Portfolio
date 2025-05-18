#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>



int power(int a, int n){
    if(n == 0) {
        return 1;
    }
    return power(a,n-1)*a;
}

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    printf("%d", power(5,5));
};