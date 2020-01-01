#include <stdio.h>

int main(void)
{

  double a[2], *d1, *d2;

  d1 = a;
  d2 = d1 + 1;
  printf("%li\n", d2 - d1); /* 1 is printed */
  printf("%li\n", (long) d2 - (long) d1); /* 8 is printed */

  char *format = "%p %d %d %d\n";
  int i = 3;
  int *p = &i;

  printf("%s%p\n", "Value of p: ", p);
  printf("%s%p\n", "Value of &p: ", &p);
  printf("%s%p\n", "Value of *&p: ", *&p);
  printf("%s%p\n", "Value of p - 2: ", p - 2); /* int is 4 bytes therefore prints an address 8 bytes less than p */
  printf("%s%li\n", "Value of (p - (p - 2)): ", (p - (p - 2))); /* 2 is printed because address of (p - 2) is 2 integers less than p */

  printf(format, p, *p + 7, 3 * **&p + 1, 5 * (p - (p - 2)));
  
  /* Number 2 exercise */

  printf("%s%d\n", "Integer value of p: ", p);
  printf("%s%d\n", "Integer value of p - 2:", p -2);

}
