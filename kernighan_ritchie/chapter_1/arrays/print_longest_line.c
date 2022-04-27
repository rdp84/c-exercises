#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000 /* maximum input line size */

int  get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int
main(void)
{
  int  c;
  int  len;              /* current line length */
  int  max;              /* maximum length seen so far */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line saved here */

  max = 0;
  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len == MAXLINE - 1 && line[len] == '\0' && line[len - 1] != '\n') {
      while ((c = getchar()) != EOF && c != '\n')
        ++len;
      if (c == '\n')
        ++len;
    }

    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) {           /* there was a line */
    if (max > MAXLINE)
      printf("The longest line exceeded the maximum number of characters.\
It had a length of %d. The following printed the first %d characters\n%s\n", max, MAXLINE - 1, longest);
    else
      printf("%s", longest);
  }

  return EXIT_SUCCESS;
}

/* getline: read a line into s, return length */
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

/* copy: copy `from` into `to`; assume `to` is big enough */
void
copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
