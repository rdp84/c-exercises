
#include <stdio.h>
#include <stdlib.h>

/* 
   Header for function is equivalent to void change_it(int *)
   Calling this function copies the base address of the array to the
   corresponding function parameter. The variables aren't changed in the calling
   environment
*/
void change_it(int []);

int main(void)
{
  int a[5], *p;
  p = a;
  printf("p has the value %p\n", p);
  change_it(a);
  p = a;
  printf("p has the value %p\n", p);

  return EXIT_SUCCESS;
}

void change_it(int a[])
{
  int i = 777, *q = &i;
  printf("a has the value %p\n", a);

  /* This assigns a new address to a. But since a is a copy this is not refelcted in the calling environment*/
  a = q;
  printf("a has the value %p\n", a);
}
