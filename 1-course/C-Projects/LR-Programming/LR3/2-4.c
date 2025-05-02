#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>


typedef enum types{
    var_int, var_double, var_char
} type;

typedef union value{
    char char_n[52];
    int int_n;
    double double_n;
} var_value;

typedef struct {
    var_value n;
    type n_type;
} Data;

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);

    int n, var;
    printf("Введите размер желаемого массива(положительное целое число): ");
    scanf("%d", &n);
    Data *array = (Data *)malloc(sizeof(Data) * n);

    //Заполнение массива
    for(int i = 0; i < n; i++){

        printf("Введите тип %d-ого элемента (1 - int, 2 - double, 3 - char): ", i + 1);
        scanf("%d", &var);

        switch (var)
        {
        case 1:
            (array+i)->n_type = var_int;
            printf("Введите целое число: ");
            scanf("%d", &(array+i)->n.int_n);
            break;
        case 2:
            (array+i)->n_type = var_double;
            printf("Введите число с плавающей запятой (в качестве разделителя точка): ");
            scanf("%lf", &(array+i)->n.double_n);
            break;
        case 3:
            (array+i)->n_type = var_char;
            printf("Введите строку: ");
            scanf("%51s", &(array+i)->n.char_n);
            break;
        default:
            printf("Неверный тип. Введите 1 для int, 2 для double или 3 для char.\n");
            i--; 
            break;
    }
}

    //Вывод массива
    printf("\nПолучившийя массив:\n");
    for (int i = 0; i < n; i++)
    {
        switch ((array+i)->n_type)
        {
        case var_int:
            printf("Элемент %d: %d, тип - Int\n",i+1,(array+i)->n.int_n);
            break;
        case var_double:
            printf("Элемент %d: %lf, тип - Double\n",i+1,(array+i)->n.double_n);
            break;
        case var_char:
            printf("Элемент %d: %s, тип - Char\n",i+1,(array+i)->n.char_n);
            break;
        }
    }
    free(array);
    
}