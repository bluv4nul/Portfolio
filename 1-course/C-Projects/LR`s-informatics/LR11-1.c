#include <stdio.h>
#include <math.h>

int main(void){

int arr[25] = {42, -7, 15, 98, -23, 0, 16, 72, -45, 8, 34, 67, -12, 9, 3, -50, 21, 5, 78, -99, 13, 27, -36, 4, 81};
int temp;

for (int i = 0; i <= 25 - 2; i++)
{
    for ( int j = 0; j <= 25 - i - 2; j++)
    {
        if (arr[j] < arr[j+1]){
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
}

for (int i = 0; i <= 25 - 1; i++)
{
    printf("%d ", arr[i]);
}
}