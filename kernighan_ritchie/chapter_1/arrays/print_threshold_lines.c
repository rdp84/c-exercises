#include <stdio.h>
#include <stdlib.h>

#define MAXLINE   1000 /* maximum input line size */
#define THRESHOLD 80   /* number of characters a line must exceed to print and we'll add a few more chars */

int  get_line(char line[], int maxline);

int
main(void)
{
  int  len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len > THRESHOLD) {
      printf("%s", line);
    }
  }

  return EXIT_SUCCESS;
}

/* get_line: read a line into s, return length */
int
get_line(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}
