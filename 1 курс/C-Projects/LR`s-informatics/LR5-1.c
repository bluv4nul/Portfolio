#include <stdio.h>
#include <math.h>

int main()
{
    double w, Xc, Xl, Z, phi;
    double f[] = { 49.8, 49.9, 50 ,50.1, 50.2 };
    double R = 50;
    double C = pow(10, -6);
    double L = pow(10, -2);
    double Jlength = sizeof(f) / sizeof(double);
    double pi = 3.1415;
    for (int i = 0; i < Jlength; i++)
    {
        w = 2 * pi * f[i];
        Xc = 1 / (w * C);
        Xl = w*L;
        Z = (Xc*sqrt(Xl*Xl+R*R))/sqrt(R*R+pow(Xl-Xc,2));
        phi = atan((Xl - Xc) / R)*(180/pi);
        printf("Freq: %lf",f[i]);
        printf("\tPhase angle:%lf", phi);
        printf("\tImpedance: % lf", Z);
        printf("\n");
    }
}