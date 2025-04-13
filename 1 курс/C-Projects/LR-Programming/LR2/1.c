#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    double ***pointer = NULL;
    double **p1 = (double **)malloc(sizeof(double *));
    double *p2 = (double *)malloc(sizeof(double));
    *p2 = 2.0;
    p1 = &p2;
    pointer = &p1;

    printf("Value: %lf", ***pointer);

    free(pointer);
    free(p1);
    free(p2);
}