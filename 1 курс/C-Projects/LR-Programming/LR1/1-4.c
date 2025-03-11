#include <stdio.h>
#include <math.h>
#include <Windows.h>

double h(double a,double b,double c,double x){
    double left = (x-a)/(pow(x*x+a*a,1.0/3.0));
    double right = (4 * pow(pow(x*x+b*b,3),1.0/4.0))/(2 + a + b + pow(pow(x-c,2),1.0/3.0));
    double res = -1 * left - right;
    return res;
}

int main(void){

    SetConsoleOutputCP(CP_UTF8);

    double A[] = {0.12,0.12,0.27};
    double B[] = {3.5,3.5,3.9};
    double C[] = {2.4,2.4,2.8};
    double X[] = {1.4,1.6,1.8};

    for(int i = 0; i < 3; i++){

        printf("%lf", h(A[i], B[i], C[i], X[i]));
        printf("\n");

    }
}