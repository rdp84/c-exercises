#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int  get_line(char s[], int limit);
void str_squeeze(char s1[], char s2[]);

int
main(void)
{
  char s1[MAXLINE];
  char s2[MAXLINE];

  while ((get_line(s1, MAXLINE)) > 0 && (get_line(s2, MAXLINE)) > 0) {
    str_squeeze(s1, s2);
    printf("%s\n", s1);
  }
  
  return EXIT_SUCCESS;
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

/* str_squeeze: deletes any characters in s2 from s1 */
void
str_squeeze(char s1[], char s2[])
{
  int i, j, k;

  for (i = k = 0; s1[i] != '\0'; ++i) {
    for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; ++j)
      ;
    if (s2[j] == '\0') /* reached the end of s2, no match */
      s1[k++] = s1[i];
  }
  s1[k] = '\0';
}
