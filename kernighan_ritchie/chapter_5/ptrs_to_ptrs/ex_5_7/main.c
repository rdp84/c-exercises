#include "lines.h"
#include "sort.h"

char allocbuf[ALLOCSIZE];
char *lineptr[MAXLINES];

int
main(void)
{
  int nlines;   /* number of input lines read */

  if ((nlines = readlines(allocbuf, lineptr, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}
