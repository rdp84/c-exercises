#include <stdio.h>
#include <stdlib.h>

int my_atoi(char s[]);

int
main(void)
{
  char s[] = "3546";
  char c   = 'a';

  int i = my_atoi(s);
  printf("%d\n", i);
  printf("%d\n", c % 16 + 9);

  return EXIT_SUCCESS;
}

/* my_atoi: convert s to integer */
int
my_atoi(char s[])
{
  int i, n;

  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
  return n;
}
