#include <stdio.h>
int main(void)
{
    int length,t;
    printf("Enter array length:");
    scanf("%d",&length);
    int array[length];
   
    printf("Enter array elements (int): \n");
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < length - 1; i = i + 2)
    {
        t = array[i];
        array[i] = array[i+1];
        array[i+1] = t;
    }

    printf("a: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d",array[i]);
    }
} 
    