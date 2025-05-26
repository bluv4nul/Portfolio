#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MY_SIZE 15

int main(void){
    // Вводим строку и удаялем \n
    char my_string[MY_SIZE];
    printf("Insert new string, about 10 characters: ");
    fgets(my_string, MY_SIZE, stdin);
    my_string[strcspn(my_string, "\n")] = '\0';

    //1. Считаем длинну без указателя
    int length = 0;
    printf("\nNo pointer:\n");
    for(int i = 0; my_string[i]!='\0'; i++){
        length++;
        printf("Symbol: %c, length = %d\n", my_string[i], length);
    }
    printf("String final lengtns: %d\n", length);


    //2. Считаем длинну через указатель
    printf("\nWith pointer:\n");
    length = 0;
    char *my_string_ptr = my_string;
    for(int i = 0; my_string_ptr[i]!='\0'; i++){
        length++;
        printf("Symbol: %c, length = %d\n", my_string_ptr[i], length);
    }
    printf("String final lengtns: %d\n", length);
    free(my_string_ptr);

    //3. Получаем длинну строки через функции
    length = strlen(my_string);
    printf("\nString length(strlen): %d\n",length);

    //4. Создаем новую строку и копируем ее в старую
    char my_string1[] = "Tomato";
    strncpy(my_string,my_string1,strlen(my_string)-1);
    printf("\nCopied string: %s\n", my_string);

    //5. Создаем еще 2 строки и делаем конкатенацию
    char my_string2[12] = "Water";
    char my_string3[] = "Melon";
    printf("\nString 1: %s String 2: %s\n",my_string2,my_string3);
    strncat(my_string2, my_string3,sizeof(my_string2)-strlen(my_string2)-1);
    printf("New string: %s\n", my_string2);

    //6. Сравниваем две новые строки заданные строковыми литералами
    printf("\nCheck using strncmp: str1:%s and str2:%s\n",my_string2, my_string3);
    int check = strncmp(my_string2, my_string3, strlen(my_string2));
    printf("strncmp(str1, str2, strlen(str1)) = %d\n", check);
    check = strncmp(my_string3, my_string2, strlen(my_string3));
    printf("strncmp(str2, str1, strlen(str2)) = %d\n", check);
    
    //7. Новая строка в нижний и верхний регист отдельно
    printf("\nString toupper and tolower\n");
    char new_string[] = "HaPpY lABor DAY";
    printf("String: %s\n",new_string);
    for(int i = 0; new_string[i] != '\0'; i++){
        new_string[i] = tolower(new_string[i]);
    }
    printf("String after to lower: %s\n",new_string);
    for(int i = 0; new_string[i] != '\0'; i++){
        new_string[i] = toupper(new_string[i]);
    }
    printf("String after to upper: %s",new_string);
}