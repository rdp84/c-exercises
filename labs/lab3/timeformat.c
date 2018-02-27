
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int hour, minute;

    printf("This program will ask you for a time in 24-hour clock format and then print out the equivalent time in 12-hour format.\n");

    printf("Please enter the hour: ");
    scanf("%d", &hour);

    printf("Please enter the minute: ");
    scanf("%d", &minute);

    if ( (hour   < 0 || hour   > 23) ||
         (minute < 0 || minute > 59) ) {

        printf("Error in input: 0 <=  hour <= 23, 0 <= minute <= 59\n");
        return EXIT_FAILURE;
    }
    else {
        if (hour == 0) {
            if (minute == 0)
                printf("12:00 midnight\n");
            else
                printf("12:%02d AM\n", minute);
        }
        else if (hour == 12) {
            if (minute == 0)
                printf("12:00 noon\n");
            else
                printf("12:%02d PM\n", minute);
        }
        else if (hour < 12)
            printf("%02d:%02d AM\n", hour, minute);
        else
            printf("%02d:%02d PM\n", hour - 12, minute);
    }
    return EXIT_SUCCESS;
}
