#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int get_line(char s[], int limit);
int any(char s1[], char s2[]);

int
main(void)
{
  char s1[MAXLINE];
  char s2[MAXLINE];
  int  i;

  while ((get_line(s1, MAXLINE)) > 0 && (get_line(s2, MAXLINE)) > 0) {
    i = any(s1, s2);
    if (i != -1)
      printf("Found a char from s2 in s1 at location %d\n", i);
    else
      printf("Didn't find a char from s2 in s1\n");
  }
}

/* get_line: read a line into s, return length */
int
get_line(char s[], int limit)
{
  char c;
  int  i;

  for (i = 0; i < limit && ((c = getchar()) != EOF && c != '\n'); ++i)
    s[i] = c;

  s[i] = '\0';
  return i;
}

/* any: returns the first location in s1 where any character from
   s2 occurs, -1 otherwise */
int
any(char s1[], char s2[])
{
  int i, j;

  for (i = 0; s1[i] != '\0'; ++i)
    for (j = 0; s2[j] != '\0'; ++j)
      if (s2[j] == s1[i])
        return i;
  return -1;
}
