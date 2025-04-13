#include <stdio.h>
#include <math.h>

int main(void){

int arr[] = {111,12,13,51,95,78,117,49,11,1,17,92,35,44,88};
double len = sizeof(arr)/sizeof(int);
double avg = 0;

for (int i = 0; i < len; i++)
{
    avg += arr[i];
}
avg /= len;

int newarr[sizeof(arr)/sizeof(int)];
for (int i = 0; i < len; i++)
{
    if (arr[i]>avg){
        newarr[i] = arr[i];
    }
    else{
        newarr[i]=0;
    }
}

printf("Avg: %lf",avg);
printf("\nnewarr:");
for (int i = 0; i < len; i++)
{
    printf(" %d",newarr[i]);
}

}