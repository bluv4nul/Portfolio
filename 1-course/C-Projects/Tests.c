#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

<<<<<<< HEAD
int main(void)
{
    int *arr = (int *)malloc(sizeof(int) * 3);
    arr[0] = 1;
    arr[2] = 10;
    arr[3] = 12;
    free(arr);
    printf("%d", arr[0]);
=======


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
>>>>>>> 6a1352ea6101ede40372cb98862eb6fbbf967b22
};