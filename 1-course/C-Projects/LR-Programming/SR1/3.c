#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

enum season{
    winter, autumn, summer, spring 
}; 

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);

    int month;
    printf("Введите номер месяца (1-12): ");
    scanf("%d",&month);

    enum season season;

    switch(month){
        case 12:
        case 1:
        case 2:
            season = winter;
            break;
        case 3:
        case 4:
        case 5:
            season = spring;
            break;
        case 6:
        case 7:
        case 8:
            season = summer;
            break;
        case 9:
        case 10:
        case 11:
            season = autumn;
            break;
    }

    switch (season)
    {
        case winter:
            printf("Winter");
            break;
        case summer:
            printf("Summer");
            break;
        case autumn:
            printf("Autumn");
            break;
        case spring:
            printf("Spring");
            break;
    }
    
}