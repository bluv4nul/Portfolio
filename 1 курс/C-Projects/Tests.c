#include <math.h>
#include <stdio.h>
#include <Windows.h>

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    int A[3][3] = { {11,27,93},{184,335,16},{71,80,912} };
    int a = sizeof(A)/sizeof(A[0]);
    printf("%d",a);
}