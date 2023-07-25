#include "tail.h"

void
tail_lines(char *lineptr[], int n, int nlines)
{
  int i;

  for (i = nlines >= n ? nlines - n : 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}
