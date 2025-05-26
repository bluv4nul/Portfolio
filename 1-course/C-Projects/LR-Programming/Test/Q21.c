/*
Напишите программу, которая создает двумерный статический массив 3x4 (3 строки, 4 столбца) целых чисел, 
заполняет его значениями matrix[i][j] = i * 10 + j, а затем выводит этот массив на экран в виде таблицы.
*/
#include <stdio.h>

#define ROWS 3
#define COLS 4

int main(void){
    int matrix[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            arr[i][j] = i * 10 + j;
        }
    }


    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}