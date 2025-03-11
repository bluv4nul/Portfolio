#include <stdio.h>
#include <math.h>
#include <Windows.h>


double sigma(double x)
{
    double s = 0;
    double ten_fact = 3628800;

    for (double z = 0; z <= 10; z+=2)
    {
        s += ((pow(z,x) + x)/ten_fact);
    }

    return s;
}

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);

    double arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int D1 = 1;
    int D2 = 5;
    int D3 = 9;
    double y;
    
    
    for (int i = 0; i <= 7; i++)
    {
        if(arr[i] >= D1 && arr[i] < D2)
        {
            y = sqrt(15+arr[i]);
            printf("%.2f\n",y);
        }
        else if(arr[i] > D2 && arr[i] <= D3)
        {
            y = sigma(arr[i]);
            printf("%.2f\n",y);
        }
        else printf("Элемент не принадлжит ни к одному из интервалов\n");
    }
}