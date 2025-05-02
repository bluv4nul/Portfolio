#include <math.h>
#include <stdlib.h>
#include <stdio.h>


int add(int a,int b){
    return a + b;
}

struct str{
    int (*ptr)(int, int);
};

int main(void)
{
    struct str str = {add};
    printf("%d", str.ptr(8,8));
}