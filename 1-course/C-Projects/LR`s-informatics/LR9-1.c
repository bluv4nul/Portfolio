#include <stdio.h>
#include <math.h>

int main(void){

int arr[] = {1,2,3,4,5,6,7,8,9,9,8,7,6,5,4,3,2,1};
int num,sum;
sum = 0;
int len = sizeof(arr)/sizeof(int); 
printf("Enter numer: ");
scanf("%d", &num);
printf("Indexes: ");
for(int i = 0; i < len; i++){
    if (arr[i] > num){
        sum+=arr[i];
        printf(" %d",i);
    } 
}
    printf("\nSum: %d",sum);
}
