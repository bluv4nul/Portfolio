#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef union 
{
    unsigned long n;
    unsigned char bytes[sizeof(unsigned long)];
} number;


int main(void)
{
    number n;
    n.n = 57599763;
    for(int i = 0; i < sizeof(n.bytes)/sizeof(unsigned char); i++){
        printf("0x%02X ", n.bytes[i]);
    }
}