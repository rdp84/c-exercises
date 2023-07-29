#include <stdio.h>

void    change_it(int []);

int
main(void)
{
  int a[5], *p;

  /*
   * Calling change_it has no effect because when an array is passed as an argument to a function,
   * the base address of the array is passed "call-by-value"; the base address is copied to the
   * parameter which means the 'a' here is not altered.
   */

  p = a;
  printf("p has the value %p\n", p);
  change_it(a);

  p = a;
  printf("p has the value %p\n", p);

  return 0;
}

void
change_it(int a[])
{
  int i = 777, *q = &i;
  a = q; // a is assigned a different value
}
