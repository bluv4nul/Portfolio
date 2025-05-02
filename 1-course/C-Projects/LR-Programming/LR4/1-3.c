#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

double** memory_for_matrix(int rows, int cols){
    double **matrix = (double **)malloc(sizeof(double *)*rows);
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (double *)malloc(sizeof(double) * cols);
    }
    return matrix;
}

void free_matrix_memory(double **matrix,int rows){
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void fill_matrix(double** matrix, int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Введите элемент матрицы с индексами [%d][%d]: ",i+1,j+1);
            scanf("%lf", &matrix[i][j]);
        }
    }
    
}

void print_matrix(double** matrix,int rows,int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    int rows = 3; int cols = 3;
    double** matrix = memory_for_matrix(rows,cols);
    fill_matrix(matrix, rows, cols);
    print_matrix(matrix, rows, cols);
    free_matrix_memory(matrix, rows);
};