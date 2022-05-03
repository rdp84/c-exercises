#include "next_day.h"

int
main(void)
{
  unsigned char today = tue;
  printf("today: %hhx\n", today);
  printf("next_day: %hhx\n", find_next_day(today));

  return EXIT_SUCCESS;
}


unsigned char
find_next_day(unsigned char day)
{
  unsigned char next_day;

  switch (day) {
  case 0x00:
    next_day = 0x01;
    break;
  case 0x01:
    next_day = 0x02;
    break;
  case 0x02:
    next_day = 0x03;
    break;
  case 0x03:
    next_day = 0x04;
    break;
  default:
    next_day = 0x05;
  }
  /*
  if (day == 0x00)
    next_day = 0x01;
  else if (day == 0x01)
    next_day = 0x02;
  else if (day == 0x03)
    next_day = 0x04;
  else
    next_day = 0x04;
  */
  return next_day;
}
