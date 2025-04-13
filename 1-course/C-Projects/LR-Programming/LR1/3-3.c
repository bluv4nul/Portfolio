#include <math.h>
#include <stdio.h>
#include <Windows.h>

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    
    int A[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
    int A_T[3][3] = { }; 

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            A_T[i][j] = A[j][i];
        }
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", A_T[i][j]);
        }
        printf("\n");
    }
}