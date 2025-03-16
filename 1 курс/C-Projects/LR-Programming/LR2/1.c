#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    double ***pointer = NULL;
    pointer = (double ***)malloc(sizeof(double **));
    *pointer = (double **)malloc(sizeof(double *));
    **pointer = (double *)malloc(sizeof(double));
    ***pointer = 2.0;
    printf("Value: %lf", ***pointer);
    free(**pointer);
    free(*pointer);
    free(pointer);
}