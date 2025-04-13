#include <stdio.h>
#include <stdlib.h>
int main(void){
    double*** pointer = NULL;


    *( *( *( pointer = malloc(sizeof(double**)) ) = malloc(sizeof(double *)) ) = malloc(sizeof(double)) ) = 2.0;

    printf("%.3lf\n", ***pointer);
    free(**pointer);
    free(*pointer);
    free(pointer);

    return 0;
}