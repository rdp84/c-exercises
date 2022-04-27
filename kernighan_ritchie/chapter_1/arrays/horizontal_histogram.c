#include <stdio.h>
#include <stdlib.h>

#define  MAX_LENGTH  10

int
main(void)
{
  int c, i, j, length, wlengths[MAX_LENGTH];

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

  for (i = 0; i < MAX_LENGTH; ++i) {
    if (i < MAX_LENGTH - 1)
      printf("%2d  ", i + 1);
    else
      printf("%2d+ ", i + 1);
    for (j = 0; j < wlengths[i]; j++)
      printf("[=]");
    printf("\n");
  }
  
  return EXIT_SUCCESS;
}
