#include <stdio.h>
#include <stdlib.h>

void expand(char s1[], char s2[]);
void expand2(char s1[], char s2[]);

int
main(void)
{
  char s1[] = "a-c-h-";
  char s2[27];
  expand2(s1, s2);
  printf("%s\n", s2);
  
  return EXIT_SUCCESS;
}

/* expand: expands shorthand notation, e.g., a-c in s1 into equivalent complete
   list in s2, e.g., abc.
   This is my solution. Not very good really, need to learn to use loop variables
   much better.
*/
void
expand(char s1[], char s2[])
{
  int i, j;
  char c;

  i = j = 0;
  
  while (s1[i] != '\0') {
    if (s1[i] == '-') {
      if (i == 0 || s1[i + 1] == '\0') /* leading or trailing - */
        c = '-';
      else {
        c = s1[i - 1] + 1;             /* get the previous char, bottom of the range */
        i++;                           /* point to top of the range */
      }
    }    
    else {
      c = s1[i];                      /* save bottom of the range */
      i += 2;                         /* update to point to top of the range */
    }

    while (c <= s1[i])                /* expand shorthand */
      s2[j++] = c++;
    i++;
  }
  s2[j] = '\0';
}

/* expand: expands shorthand notation, e.g., a-c in s1 into equivalent complete
   list in s2, e.g., abc.
   Textbook solution, making clever use of loop variables
*/
void
expand2(char s1[], char s2[])
{
  int  i, j;
  char c;

  i = j = 0;
  
  while ((c = s1[i++]) != '\0') {          /* get a char */
    if (s1[i] == '-' && s1[i + 1] >= c) {  /* in a range */
      i++;
      while (c < s1[i])                    /* expand shorthand */
        s2[j++] = c++;
    } else
      s2[j++] = c;                         /* else it is just c */
  }
  s2[j] = '\0';
}
