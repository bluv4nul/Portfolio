#include <stdio.h>
#include <windows.h>

int main(void)
{

SetConsoleOutputCP(CP_UTF8);
int arr[3][3]= {
    {12,22,13},
    {47,52,61},
    {7,80,19}
};

for (int i = 1; i < 3; i++)
{
    for(int j = 0; j < i; j ++)
    {
        arr[i][j] = 0;
    }
}

for (int i = 0; i <= 2; i++)
{
    for (int j = 0; j <= 2; j++)
    {
        printf("%d\t",arr[i][j]);
    }
    printf("\n");
}

}