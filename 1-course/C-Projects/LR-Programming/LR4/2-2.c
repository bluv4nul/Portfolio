#include <stdio.h>
#include <stdlib.h>

#define size 12

int main(void){

    char *str1 = (char *)malloc(sizeof(char)*size);
    char *str2 = (char *)malloc(sizeof(char)*size);
    printf("Insert int-number, max 10 characters: ");
    fgets(str1, size, stdin);
    printf("Insert double-number, max 10 characters: ");
    fgets(str2, size, stdin);

    int num1 = atoi(str1);
    free(str1);
    double num2 = atof(str2);
    free(str2);

    printf("num1(int) = %d num2(double) = %lf", num1, num2);
}