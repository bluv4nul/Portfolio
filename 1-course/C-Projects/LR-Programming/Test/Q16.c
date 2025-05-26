//Напишите функцию swap_pointers, которая принимает два указателя на целые числа (int*) и меняет местами значения, на которые они указывают.
#include <stdio.h>

void swap_pointers(int* ptr1, int* ptr2) {
    *ptr1 ^= *ptr2;
    *ptr2 ^= *ptr1;
    *ptr1 ^= *ptr2;
}

int main() {
    int a = 10;
    int b = 20;
    printf("До обмена: a = %d, b = %d\n", a, b);
    swap_pointers(&a, &b);
    printf("После обмена: a = %d, b = %d\n", a, b);
    return 0;
}