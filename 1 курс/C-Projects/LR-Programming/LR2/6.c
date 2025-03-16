#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);

    int a = 1234567890;
    char *ptr = (char *)&a;

    printf("Побайтовый вывод переменной:\n");
    for(int i = 0; i < sizeof(a);i++)
    {
        printf("Байт%d: %02x\n",i,(unsigned char)ptr[i]);
    }
    free(ptr);
}