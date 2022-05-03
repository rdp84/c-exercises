#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int  get_line(char s[], int limit);
void char_squeeze(char s[], int c);

int
main(void)
{
  char c = 'e';
  char line[MAXLINE];

  while ((get_line(line, MAXLINE)) > 0) {
    char_squeeze(line, c);
    printf("%s", line);
  }
  
  return EXIT_SUCCESS;
}

/* getline: read a line into s, return length */
int
get_line(char s[], int limit)
{
  char c;
  int  i;

  for (i = 0; i < limit - 1 && ((c = getchar()) != EOF && c != '\n'); ++i)
    s[i] = c;

  if (c == '\n')
    s[i++] = '\n';

  s[i] = '\0';
  return i;
}

/* char_squeeze: delete all c from s */
void
char_squeeze(char s[], int c)
{
  int i, j;

  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c)
      s[j++] = s[i];

  s[j] = '\0';
}
