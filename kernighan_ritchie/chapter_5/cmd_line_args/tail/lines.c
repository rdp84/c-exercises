#include "lines.h"

/* get_line: read a line into s, return length */
int
get_line(char *s, int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    *s++ = c;

  if (c == '\n') {
    *s++ = c;
    ++i;
  }

  *s = '\0';
  return i;
}

/* str_cpy: copy t to s */
void
str_cpy(char *s, char *t)
{
  while ((*s++ = *t++))
    ;
}

/* readlines: read input lines */
int
readlines(char allocbuf[], char *lineptr[], int maxlines)
{
  int len, nlines;
  char line[MAXLEN], *p = allocbuf, *allocstop = allocbuf + ALLOCSIZE;

  nlines = 0;
  while ((len = get_line(line, MAXLEN)) > 0)
    if (nlines >= maxlines || p + len > allocstop)
      return -1;
    else {
      line[len - 1] = '\0';
      str_cpy(p, line);
      lineptr[nlines++] = p;
      p += len;
    }
  return nlines;
}
