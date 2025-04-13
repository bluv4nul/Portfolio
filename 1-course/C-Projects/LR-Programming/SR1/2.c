#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

struct book
{
    char title[50];
    char author[50];
    int year;
};

void printBook(struct book *book)
{
    printf("Название книги: %s\n", book -> title);
    printf("Автор книги: %s\n", book -> author);
    printf("Год издания книги: %d\n", book -> year);
}

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);

    struct book arr_books[3];
    printf("Введите 3 книги:\n");
    printf("__________________________\n");
    for(int i = 0; i < 3; i++)
    {
        printf("Введите название %d книги: ", (i+1));
        fgets(arr_books[i].title, 50, stdin);
        printf("Введите автора %d книги: ", (i+1));
        fgets(arr_books[i].author, 50, stdin);
        printf("Введите год написания %d книги: ", (i+1));
        scanf("%d", &arr_books[i].year);
        printf("__________________________\n");
        getchar();
    }

    for(int i = 0; i < 3; i++){
        printBook(&arr_books[i]);
        printf("__________________________\n");
    }
}