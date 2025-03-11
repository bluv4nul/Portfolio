#include <math.h>
#include <stdio.h>
#include <Windows.h>

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);

    int A[3][3] = { {11,27,93},{184,335,16},{71,80,912} };
    int s = 0;
    int rows = sizeof(A) / sizeof(A[0]);
    int cols = sizeof(A[0]) / sizeof(A[0][0]);


    printf("Исходная матрица: \n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            s += A[i][j];
        }
        A[i][0] = s/cols;
        s = 0;
    }
    printf("\n");
    printf("Полученная матрица: \n");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    
}