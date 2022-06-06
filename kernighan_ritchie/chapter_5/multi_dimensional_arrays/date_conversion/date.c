#include "date.h"

#define LEAP(year)  ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int
day_of_year(int year, int month, int day)
{
  int i, leap = LEAP(year);

  if (month < 1 || month > 12 || day < 1 || day > daytab[leap][month]) {
    printf("error: invalid date entered\n");
    return 0;
  }

  for (i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;

  /*
    Exercise 5-9:

    char *p = daytab[LEAP(year)];

    while (--month)
      day += *++p;
    return day;
   */
}

/* month_day: set month, day from day of year */
void
month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap = LEAP(year);
  
  if (yearday < 1 || yearday > (leap ? 366 : 365)) {
    printf("error: invalid day of year entered\n");
    *pmonth = 0;
    *pday = 0;
    return;
  }

  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;

  /*
    Exercise 5-9:

    char *p = daytab[LEAP(year)];
    *pday = yearday;
    *pmonth = 1;

    while (*pday > *++p) {
      *pday -= *p;
      *pmonth += 1;
    }
   */
}

/* month_name: return name of the n-th month */
char *
month_name(int n)
{
  static char *name[13] = {
    "Illegal month",
    "January", "February", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December"
  };

  return (n < 1 || n > 12) ? name[0] : name[n];
}
