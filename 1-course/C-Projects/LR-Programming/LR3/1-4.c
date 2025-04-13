#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char name[10];
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 11; 
} Birthday;

int print_birthday(Birthday Person){
    if(Person.month < 10){
        printf("%s`s birthday: %d.0%d.%d\n", Person.name, Person.day, Person.month, Person.year);   
    }
    else{
        printf("%s`s birthday: %d.%d.%d\n", Person.name, Person.day, Person.month, Person.year);   

    }
}
int main(void)
{
    Birthday Andrew = {"Andrew",20, 4, 2006};
    Birthday Max = {"Max", 12, 12, 2012};
    print_birthday(Andrew);
    print_birthday(Max);   
}