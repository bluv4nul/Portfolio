#include <stdio.h>
#include <math.h>

int main(void){

double M;
double U = 1;
double S = 1;
double x = 0.5;
double k = 1;

do
{
    M = x/k;
    U *= M;
    S += U;
    k++;
} while (U > 0.0001);

printf("U: %lf\t", U);
printf("k: %lf\t", k);
printf("S: %lf", S);
}