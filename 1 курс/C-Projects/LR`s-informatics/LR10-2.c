#include <stdio.h>
#include <math.h>
#include <Windows.h>

int main(void){
SetConsoleOutputCP(CP_UTF8);

int n;
scanf("%d",&n);
int lastnum = n%10;
if (n >= 11 && n <= 14){
    printf("Ворон");
}
else{
    switch (lastnum)
    {
    case 1:
        printf("Ворона");
        break;
    case 2:
        printf("Вороны");
        break;
    case 3:
        printf("Вороны");
        break;
    case 4:
        printf("Вороны");
        break;
    default:
        printf("Ворон");
        break;
    }
}
}

