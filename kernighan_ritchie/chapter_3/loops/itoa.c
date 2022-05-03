#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

void reverse(char s[]);
void itoa(int n, char s[]);
void itoa_ex(int n, char s[]);
void itoa_width(int n, char s[], int width);

int
main(void)
{
  char s[32];
  int  i;
  
  i = 3567;
  printf("i: %d\n", i);

  itoa(i, s);
  printf("s: %s\n", s);

  itoa_width(i, s, 6);
  printf("%s\n", s);

  itoa_width(i * -1, s, 6);
  printf("%s\n", s);
  
  i = -2147483648;
  printf("i: %d\n", i);

  itoa(i, s);
  printf("s: %s\n", s);

  itoa_ex(i, s);
  printf("s: %s\n", s);
  
  return EXIT_SUCCESS;
}

/* itoa: convert n to characters in s */
void
itoa(int n, char s[])
{
  int i, sign;

  if ((sign = n) < 0)        /* record sign */
    n = -n;                  /* make n positive */
  i = 0;

  do {                       /* generate digits in reverse order */
    s[i++] = n % 10 + '0';   /* get next digit */
  } while ((n /= 10) > 0);   /* delete it */

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';

  reverse(s);
}

/* itoa: convert n to characters in s.
   Handles larges negative numbers in s's complement */
void
itoa_ex(int n, char s[])
{
  int i, sign;

  sign = n;                      /* record sign */
  i = 0;
  do {                           /* generate digits in reverse order */
    s[i++] = abs(n % 10) + '0';  /* get next digit */
  } while ((n /= 10) != 0);      /* delete it */

  if (sign < 0)
    s[i++] = '-';

  s[i] = '\0';
  reverse(s);
}

/* itoa_width: convert n to characters in s, width characters wide */
void
itoa_width(int n, char s[], int width)
{
  int i, sign;

  sign = n;                     /* record sign */
  i = 0;
  do {                          /* generate digits in reverse order */
    s[i++] = abs(n % 10) + '0'; /* get next digit */
  } while ((n /= 10) != 0);     /* delete it */

  if (sign < 0)
    s[i++] = '-';

  while (i < width)             /* pad with blanks */
    s[i++] = ' ';
  
  s[i] = '\0';
  reverse(s);
}

/* reverse: reverse string s in place */
void
reverse(char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
