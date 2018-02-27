
#include <stdio.h>
#include <stdlib.h>

int number_of_days(int, int);
char* get_day_of_week(int);

int main(void)
{

    int day, month, days;
    char* day_of_week;

    printf("Please enter the day of the month: ");
    scanf("%d", &day);

    printf("Please enter the month: ");
    scanf("%d", &month);

    days = number_of_days(day, month);
    day_of_week = get_day_of_week(days);

    printf("It was a %s\n", day_of_week);
 
    return EXIT_SUCCESS;
}

int number_of_days(int day, int month)
{
    int days = 0;

    --month;
    while (month > 0) {

        if (month == 2)
            days += 28;
        else if (month == 4 || month == 6 || month == 9 || month == 11)
            days += 30;
        else
            days += 31;

        --month;
    }

    return days + day;
}

char* get_day_of_week(int days)
{

   int day_of_week = days % 7;

    if (day_of_week == 1)
        return "Sunday";
    else if (day_of_week == 2)
        return "Monday";
    else if (day_of_week == 3)
        return "Tuesday";
    else if (day_of_week == 4)
        return "Wednesday";
    else if (day_of_week == 5)
        return "Thursday";
    else if (day_of_week == 6)
        return "Friday";
    else
        return "Saturday";
}

