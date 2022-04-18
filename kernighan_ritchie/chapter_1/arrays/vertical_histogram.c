#include <stdio.h>
#include <stdlib.h>

#define  MAX_LENGTH  10

int
main(void)
{
  int c, i, j, length, highest_count, wlengths[MAX_LENGTH];

  length = 0;
  for (i = 0; i < MAX_LENGTH; ++i)
    wlengths[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (length > MAX_LENGTH)
        ++wlengths[MAX_LENGTH - 1];
      else if (length > 0)
        ++wlengths[length - 1];

      length = 0;
    }
    else {
      ++length;
    }
  }

  highest_count = 0;
  for (i = 0; i < MAX_LENGTH; ++i) {
    if (wlengths[i] > highest_count)
      highest_count = wlengths[i];
  }

  for (i = highest_count; i > 0; --i) {
    for (j = 0; j < MAX_LENGTH; ++j) {
      if (wlengths[j] >= i) {
        putchar('[');
        putchar('=');
        putchar(']');
      }
      else {
        putchar(' ');
        putchar(' ');
        putchar(' ');
      }
    }
    putchar('\n');
  }

  printf(" 1  2  3  4  5  6  7  8  9 10+\n");
  return EXIT_SUCCESS;
}
