#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

void Cross_Product(int* vec1, int* vec2, int* result){
    result[0] = vec1[1]*vec2[2] - vec1[2]*vec2[1];
    result[1] = vec1[2]*vec2[0] - vec1[0]*vec2[2];
    result[2] = vec1[0]*vec2[1] - vec1[1]*vec2[0];
}

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    int vector1[] = {1, 2, 3};
    int vector2[] = {8, 9, 10};
    int result[3];
    printf("Исходные векторы: (%d,%d,%d) и (%d,%d,%d)\n", vector1[0],vector1[1],vector1[2],vector2[0],vector2[1],vector2[2]);
    Cross_Product(vector1,vector2,result);
    printf("Получившееся произведение: (%d,%d,%d)", result[0],result[1],result[2]);
}