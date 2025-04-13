#include <stdio.h>
#include <math.h>
#include <Windows.h>

int main(void){

    SetConsoleOutputCP(CP_UTF8);

    double x,y;
    printf("Введите x\t");
    scanf("%lf",&x);
    printf("Введите y\t");
    scanf("%lf",&y);

    double chislitel = 1 + (sin(x+y)*sin(x+y));
    double znamenatel = 2 + (fabs(x - (2*x*x)/(1+fabs(sin(x+y)))));
    double res = chislitel/znamenatel;

    printf("U(x,y) =  %lf", res);
}