#include "lines.h"
#include "tail.h"

char allocbuf[ALLOCSIZE];
char *lineptr[MAXLINES];

int
main(int argc, char *argv[])
{
  char c, *arg;
  int nlines, n = 0;

  if (argc > 2)
    n = -1;
  else if (argc == 2) {
    arg = *++argv;
    if (*arg == '-') {
      while ((c = *++arg)) {
        if (c >= '0' && c <= '9')
          n = 10 * n + (c - '0');
        else {
          n = -1;
          break;
        }
      }
    }
    else
      n = -1;
  }
  else
    n = 10;

  if (n <= 0) {
    printf("usage: tail -n\n");
    return -1;
  }
  
  if ((nlines = readlines(allocbuf, lineptr, MAXLINES)) >= 0) {
    tail_lines(lineptr, n, nlines);
    return 0;
  } else {
    printf("error: input too big to tail\n");
    return 1;
  }
}
