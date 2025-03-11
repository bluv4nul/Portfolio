#include <stdio.h>
#include <Windows.h>

int main(void){

    SetConsoleOutputCP(CP_UTF8);

    int a,b;
    printf("Введите 1 число\t");
    scanf("%d",&a);
    printf("Введите 2 число\t");
    scanf("%d",&b);
    int res = a + b;
    printf("Результат: %d",res);
}
