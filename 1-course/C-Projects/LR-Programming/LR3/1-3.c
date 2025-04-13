#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

typedef struct
{
    double real; // Действительная часть
    double imag; // Мнимая часть
} complex;

complex complex_add(complex a, complex b)
{
    complex res;
    res.real = a.real + b.real;
    res.imag = a.imag + b.imag;
    return res;
}

complex complex_mult(complex a, complex b)
{
    complex res;
    res.real = a.real * b.real - a.imag * b.imag;
    res.imag = a.real * b.imag + a.imag * b.real;
    return res;
}

complex complex_div_scalar(complex a, double scalar)
{
    complex res;
    res.real = a.real / scalar;
    res.imag = a.imag / scalar;
    return res;
}

complex complex_exp(complex z, int terms)
{
    complex sum = {1.0, 0.0};  // Начальное значение: 1 + 0i
    complex term = {1.0, 0.0}; // Текущий член ряда: z^n / n!

    for (int n = 1; n <= terms; n++)
    {
        term = complex_mult(term, z);       // *=z
        term = complex_div_scalar(term, n); // term /= n
        sum = complex_add(sum, term);       // sum +=term
    }

    return sum;
}

int main(void){
    complex z = {1.0,1.0};
    complex ez = complex_exp(z,10);

    printf("exp(z) = %.6lf + %.6lf", ez.real, ez.imag);
}