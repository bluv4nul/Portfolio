#include <math.h>
#include <stdio.h>
#include <Windows.h>
#define M_PI  3.14159265358979323846


int main(void)
{
    SetConsoleOutputCP(CP_UTF8);

    double r1 = 227.9;
    double r2 = 149.6;
    double T1 = 687;
    double T2 = 365.25;

    double w1 = (2*M_PI)/T1;
    double w2 = (2*M_PI)/T2;


    for(int t = 0; t <= 780; t+= 20)
    {
        double x = r1*cos(w1*t) - r2*cos(w2*t);
        double y = r1*sin(w1*t) - r2*sin(w2*t);
        printf("t=%d\tx=%lf\ty=%lf\n", t, x, y); 
    }

}