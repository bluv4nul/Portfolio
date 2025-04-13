#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //Создаем тройной указатель и инициализируем NULL
    double ***pointer = NULL;
    
    //Выделяем память под double** (второй уровень)
    pointer = (double***)malloc(sizeof(double**));
    
    //Выделяем память под double* (первый уровень)
    *pointer = (double**)malloc(sizeof(double*));
    
    //Выделяем память под само double (значение)
    **pointer = (double*)malloc(sizeof(double));
    
    //Записываем значение 2.0
    ***pointer = 2.0;
    
    //Выводим значение
    printf("%lf\n", ***pointer);
    
    //Освобождаем память в обратном порядке
    free(**pointer); //освобождаем double
    free(*pointer);  //освобождаем double*
    free(pointer);   //освобождаем double**
    
    return 0;
}