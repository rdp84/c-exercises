#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 10

int get_line(char line[], int maxline);

int
main(void)
{
  int  c, i, len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len > 1) {
      if (line[len - 1] != '\n') {
        while ((c = getchar()) != EOF && c != '\n')
          ;
        printf("%s\n", line);
      }
      else {
        i = len - 2;
        while (line[i] == ' ' || line[i] == '\t')
          --i;
        if (i < len - 2) {
          line[i + 1] = '\n';
          line[i + 2] = '\0';
        }
        printf("%s", line);
      }
    }
  }
}

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
