#include <stdio.h>
#include <math.h>

int main(void){

int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int sum = 0;
int len = sizeof(arr)/sizeof(int);
for (int i = 0; i < len; i++)
{
    if(arr[i]%2==0){
        sum += arr[i];
    }
}
printf("Sum: %d",sum);
}