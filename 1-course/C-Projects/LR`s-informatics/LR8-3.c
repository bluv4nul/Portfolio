#include <stdio.h>
#include <math.h>

int main(void){

double M;
double x = 3.14159265/6;
double U = 1;
double S = 1;
double k = 1;

do
{
    M = -(x*x)/(2*k*(2*k-1));
    U = M*U;
    S += U;
    k++;
} while (fabs(U) > 0.0001);

printf("U: %lf\t", U);
printf("k: %lf\t", k);
printf("S: %lf", S);
}