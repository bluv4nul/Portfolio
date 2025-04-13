#include <stdio.h>

int main(void)
{
    int A[] = {1,2,3,4,5};
    int B[] = {6,7,8,9,10};
    int C[10];
    for (int i = 0; i < 5; i++)
    {
        C[i] = A[i];
        C[i+5] = B[i];
        
    }

    printf("C:");
    for (int i = 0; i < 10; i++)
    {
        printf("%d",C[i]);
    }
 }