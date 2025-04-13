#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);

    double **p_matrix = NULL;
    int rows, cols;

    printf("Введите количество строк: ");
    scanf("%d",&rows);
    printf("Введите количество столбцов: ");
    scanf("%d",&cols);

    p_matrix = (double **)malloc(rows * sizeof(double*));

    for(int i = 0; i<rows;i++){
        p_matrix[i] = (double *)malloc(cols*sizeof(double));
    }

    for(int i = 0; i < rows; i++)
    {
        free(p_matrix[i]);
    }
    
    free(p_matrix);
}