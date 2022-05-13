#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000      /* maximum input line length */

int get_line(char line[], int max);
int strindex(char source[], char searchfor[]);
int strindex_right(char source[], char searchfor[]);
int strindex_right_efficient(char source[], char searchfor[]);

char pattern[] = "ould";

/* find all lines matching pattern */
int
main(void)
{
  char line[MAXLINE];
  int  found = 0;

  while (get_line(line, MAXLINE) > 0)
    if (strindex(line, pattern) >= 0) {
      printf("%s", line);
      found++;
    }

  return found;
}

/* getline: get line into s, return length */
int
get_line(char s[], int lim)
{
  int c, i;

  i = 0;
  while(--lim > 0 && ((c = getchar()) != EOF) && c != '\n')
    s[i++] = c;

  if (c == '\n')
    s[i++] = c;

  s[i] = '\0';
  return i;
}

/* strindex: return index of t in s, -1 if none */
int
strindex(char s[], char t[])
{
  int i, j, k;

  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}

/* strindex: returns rightmost index of t in s, -1 if none */
int
strindex_right(char s[], char t[])
{
  int i, j, k, pos;

  pos = -1;
  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      pos = i;
  }
  return pos;
}

/* strindex: returns rightmost index of t in s, -1 if none.
   More efficient than above solution.
*/
int
strindex_right_efficient(char s[], char t[])
{
  int i, j, k;

  for (i = strlen(s) - strlen(t); i >= 0; i--) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}
