#include <math.h>
#include <stdio.h>
#include <Windows.h>

double f(double x)
{
	return exp(x+2);
}
double trapezoid(double a, double b, double n)
{
	double r, h;
	h = (b - a) / n;
	r = 0;
	for (double i = a + h; i <= b - h; i = i + h)
	{
		r = r + f(i);ч10
        
	}
	return h * ((f(a) + f(b)) / 2 + r);
}

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    double a, b, n;
    printf("Enter the lower integration limit (a):\n");
    scanf_s("%lf", &a);
    printf("Enter the upper integration limit (b):\n");
    scanf_s("%lf", &b);
    printf("Enter the number of splits (n):\n");
    scanf_s("%lf", &n);
    printf("%lf", trapezoid(a,b,n));
}