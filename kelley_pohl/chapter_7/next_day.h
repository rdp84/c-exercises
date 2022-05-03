#include <stdio.h>
#include <stdlib.h>

typedef enum {
  sun = 0x00,
  mon = 0x01,
  tue = 0x03,
  wed = 0x04,
  thu = 0x05,
  fri = 0x06,
  sat = 0x07
} day;

unsigned char find_next_day(unsigned char day);
