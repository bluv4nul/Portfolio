#include <stdio.h>
int main(void){

int arr[25] = {42, -7, 15, 98, -23, 0, 16, 72, -45, 8, 34, 67, -12, 9, 3, -50, 21, 5, 78, -99, 13, 27, -36, 4, 81};
int temp;

for (int i = 0; i <= 25 - 2; i++)
{
    int max_index = i;
    for ( int j = i+1; j <= 25 - 1; j++)
    {
        if (arr[j] > arr[max_index]){
            max_index = j;
        }
    }
    temp = arr[max_index];
    arr[max_index] = arr[i];
    arr[i] = temp;
}

for (int i = 0; i <= 25-1; i++)
{
    printf("%d ", arr[i]);
}

}