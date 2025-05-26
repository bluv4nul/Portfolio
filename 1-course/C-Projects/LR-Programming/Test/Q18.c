/*Определите структуру Point с двумя членами x и y (типа double). 
Напишите программу, которая создает массив из 3-х таких структур, 
инициализирует их значениями (например, (1.0, 2.0), (3.5, 4.1), (0.5, 5.5)), 
а затем вычисляет и выводит расстояние от начала координат (0,0) до каждой точки.*/
#include <stdio.h>
#include <math.h>
#include <windows.h>

typedef struct point
{
    double x;
    double y;
} point;

int main(void){
    SetConsoleOutputCP(CP_UTF8);

    point arr[3] = {
        {1.1, 2.2},  
        {3.3, 4.4},  
        {5.5, 6.6}   
    };

    double distance;
    for(int i = 0; i < 3; i++){
        printf("Точка %d: (%.1lf, %.1lf)\n", i+1, arr[i].x,arr[i].y);
        distance = sqrt(arr[i].x*arr[i].x+arr[i].y*arr[i].y);
        printf("Расстояние от (0, 0) до точки = %.1lf\n\n", distance);
    }

}
