#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int get_line(char line[], int lim);
void reverse(char str[]);

int
main(void)
{
  int  len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    reverse(line);
    printf("%s", line);
  }

  return EXIT_SUCCESS;
}

int
get_line(char line[], int lim)
{
  int  i;
  char c;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';
  return i;
}

void
reverse(char s[])
{
  int  i, j;
  char temp;

  i = j = 0;

  while (s[i] != '\0')
    ++i;

  i -= 2;
  while (j < i) {
    temp = s[j];
    s[j] = s[i];
    s[i] = temp;

    ++j;
    --i;
  }
}
