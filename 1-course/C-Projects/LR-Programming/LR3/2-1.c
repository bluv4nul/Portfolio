#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef union 
{
    char ch[10];
    int i;
    double d;
} Var;


int main(void)
{
    Var *ptr = (Var *)malloc(sizeof(Var));
    strcpy(ptr->ch, "Home");
    printf("%s\n", ptr->ch);
    ptr->i = 10;
    printf("%d\n", ptr->i);
    ptr->d = 15.5;
    printf("%.1lf\n", ptr->d);
    free(ptr);
}