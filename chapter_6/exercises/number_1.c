#include <stdio.h>

int main(void)
{
  /*
  int a[2], *p, *q;

  p = a;
  q = p + 1;
  printf("%li\n", q - p);
  printf("%li\n", (long int) q - (long int) p);
  */

  char *format = "%p %d %d %d\n";
  int i = 3;
  int *p = &i;

  printf("%s%li\n", "Value of p: ", (p - (p - 2)));
  printf(format, p, *p + 7, 3 * **&p + 1, 5 * (p - (p - 2)));
}
