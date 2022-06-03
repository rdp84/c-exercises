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

/* strcpy: copy t to s */
void
str_cpy(char *s, char *t)
{
  while ((*s++ = *t++))
    ;
}

/* readlines: read input lines */
int
readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = get_line(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len - 1] = '\0'; /* delete new line character */
      str_cpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

/* writelines: wite output lines */
void
writelines(char *lineptr[], int nlines)
{
  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}
