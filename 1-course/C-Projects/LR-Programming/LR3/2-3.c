#include <stdlib.h>
#include <stdio.h>
#include <string.h>


enum WeekDays{
    MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
};


int main(void)
{
    printf("Monday: %d\n", MONDAY);
    printf("Tuesday: %d\n", TUESDAY);
    printf("Wednesday: %d\n", WEDNESDAY);
    printf("Thursday: %d\n", THURSDAY);
    printf("Friday: %d\n", FRIDAY);
    printf("Saturday: %d\n", SATURDAY);
    printf("Sunday: %d", SUNDAY);
}