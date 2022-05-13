#include <stdio.h>
#include <ctype.h>

#define MAXLINE  1000

/* rudimentary calculator */
int
main(void)
{
  double sum, atof(char []);
  char line[MAXLINE];
  int get_line(char line[], int max);

  sum = 0;
  while(get_line(line, MAXLINE) > 0)
    printf("\t%g\n", sum += atof(line));
  return 0;
}

/* get_line: get line into s, return length */
int
get_line(char line[], int max)
{
  char c;
  int  i;
  
  i = 0;
  while (--max > 0 && ((c = getchar()) != EOF) && c != '\n')
    line[i++] = c;

  if (c == '\n')
    line[i++] = c;

  line[i] = '\0';
  return i;
}

/* atof: convert string s to double */
double
atof(char s[])
{
  double val, power;
  int i, sign, exp;

  for (i = 0; isspace(s[i]); i++)          /* skip white space */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  val = sign * val / power;
  
  if (s[i] == 'e' || s[i] == 'E') {
    sign = (s[++i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
      i++;
    for (exp = 0; isdigit(s[i]); i++)
      exp = 10 * exp + (s[i] - '0');
    if (sign == 1)
      while (exp-- > 0)                    /* positive exponent */
        val *= 10;
    else
      while (exp-- > 0)                    /* negative exponent */
        val /= 10;
  }

  return val;
}
