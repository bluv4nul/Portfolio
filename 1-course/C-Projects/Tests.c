#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

int main(void)
{
    int *arr = (int *)malloc(sizeof(int) * 3);
    arr[0] = 1;
    arr[2] = 10;
    arr[3] = 12;
    free(arr);
    printf("%d", arr[0]);
};