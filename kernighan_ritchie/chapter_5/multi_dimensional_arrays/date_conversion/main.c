#include "date.h"

int
main(void)
{
  int day, pmonth, pday;
  char *name;

  day = day_of_year(2022, 2, 29);
  if (day)
    printf("day_of_year(2022, 6, 4): %d\n", day);

  month_day(2022, 366, &pmonth, &pday);
  if (pmonth && pday)
    printf("month_day(2022, 155, &pmonth, &pday):\n\tpmonth: %d, pday: %d\n", pmonth, pday);

  name = month_name(3);
  printf("month_name(3): %s\n", name);

  return EXIT_SUCCESS;
}
