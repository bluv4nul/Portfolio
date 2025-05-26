/*
Напишите функцию count_char, 
которая принимает строку (массив символов char*) и символ char в качестве аргументов и 
возвращает количество вхождений этого символа в строку.\
*/
#include <stdio.h>
#include <windows.h>

int count_char(const char* str, char target) {
    if (*str == '\0') return 0;
    return (*str == target) + count_char(str+1,target);
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    char my_string[] = "Programming in C is fun!";
    char char_to_find = 'n';
    int occurrences = count_char(my_string, char_to_find);
    printf("Символ '%c' встречается %d раз(а).\n", char_to_find, occurrences);
    return 0;
}

