#include <math.h>
#include <stdio.h>

int main(void){

double lambd = 0.1;
double pi = 3.1415926536;
double D = 30 * pi / 180;
double phi = 45 * pi / 180;
double sinA = cos(phi) * sin(lambd) / sin(D);
double cosA = (sin(phi)-sin(phi)*cos(D))/cos(phi)*sin(D);
double A = asin(cos(phi)*(sin(lambd)/sin(D)));

if (sinA > 0 && cosA > 0){
    A = fabs(A);
}
if (sinA > 0 && cosA < 0){
    A = pi - fabs(A);
}
if (sinA < 0 && cosA < 0){
    A = pi + fabs(A);
}
if (sinA < 0 && cosA > 0){
    A = 2*pi - fabs(A);
}
A = A * 180 / pi;
printf("%lf",A);
}