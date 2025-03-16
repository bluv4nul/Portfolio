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
    if(p_matrix == NULL)
    {
        printf("Error!");
        return 1;
    }
    
    for(int i = 0; i<rows;i++){
        p_matrix[i] = (double *)malloc(cols*sizeof(double));
    }

    for(int i = 0;i<rows;i++){
        for(int  j = 0;j<cols;j++){
            p_matrix[i][j] = 1;
        }
    }

    for(int i = 0;i<rows;i++){
        for(int  j = 0;j<cols;j++){
            printf("%.2lf ",p_matrix[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < rows; i++)
    {
        free(p_matrix[i]);
    }
    free(p_matrix);
}