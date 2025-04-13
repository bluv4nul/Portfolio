#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

typedef struct {
    char name[2];
    int x;
    int y;
    int z;
} Vector;

//Модуль (Длинна)
double Module(Vector a)
{
    return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

//Скалярное произведение
int Dot_Product(Vector a, Vector b){
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

//Вектороное произведение
Vector Cross_Product(Vector a, Vector b){
    Vector result = {"c",a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z ,a.x * b.y -a.y * b.x};
    return result; 
}

//Вывод вектора
void print_vector(Vector a){
    printf("Вектор %s: (%d,%d,%d)\n",a.name, a.x, a.y, a.z);
}

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);

    Vector a = {"a",1,2,3};
    Vector b = {"b",8,9,10};

    printf("Векторы a и b: (x, y, z)\n");
    print_vector(a);
    print_vector(b);
    printf("\n");
    printf("Модуль вектора %s = %.2lf\n", a.name, Module(a));
    printf("Модуль вектора %s = %.2lf\n", b.name, Module(b));
    printf("\n");
    printf("Скалярное произведение %s на %s = %d\n", a.name,b.name,Dot_Product(a,b));
    printf("Скалярное произведение %s на %s = %d\n", b.name,a.name,Dot_Product(b,a));
    printf("Скалярные произведения равны, так как данная операция коммутативна.\n");
    printf("\n");
    printf("Векторное произведение %s на %s: ",a.name, b.name);
    print_vector(Cross_Product(a,b));
    printf("Векторное произведение %s на %s: ",b.name, a.name);
    print_vector(Cross_Product(b,a));
    printf("Векторное произведение антикоммутативно, a*b = -(b*a)");
}
