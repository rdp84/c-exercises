/* Compute the next day */

#include <stdio.h>
#include <stdlib.h>

enum day {sun, mon, tue, wed, thu, fri, sat};
typedef enum day day; /* the usual typedef trick */
day find_next_day(day);

int main(void)
{
  day today = sat;
  printf("today: %d\n", today);
  day tomorrow = find_next_day(today);
  printf("tomorrow: %d\n", tomorrow);

  return EXIT_SUCCESS;
}

day find_next_day(day d)
{
  day next_day;

  switch (d) {
  case sun:
    next_day = mon;
    break;
  case mon:
    next_day = tue;
    break;
  case tue:
    next_day = wed;
    break;
  case wed:
    next_day = thu;
    break;
  case thu:
    next_day = fri;
    break;
  case fri:
    next_day = sat;
    break;
  case sat:
    next_day = sun;
    break;
  }
  return next_day;
}
