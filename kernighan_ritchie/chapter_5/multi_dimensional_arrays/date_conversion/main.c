#include "date.h"

int
main(void)
{
  int day, pmonth, pday;
  day = day_of_year(2022, 2, 29);
  if (day)
    printf("day_of_year(2022, 6, 4): %d\n", day);

  month_day(2022, 366, &pmonth, &pday);
  if (pmonth && pday)
    printf("month_day(2022, 155, &pmonth, &pday):\n\tpmonth: %d, pday: %d\n", pmonth, pday);


  
  return EXIT_SUCCESS;
}
