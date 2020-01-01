
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i = 4, j = 5, *p, *q; /* j = 6, *p, *q; */

  p = &i; // &*&i also compiles without warning - circular reference
  printf("%s%d\n", "p = ", *p);

  // int k = (int) p; compiles with a warning - casting from pointer to int which are of different size
  // printf("%s%d\n", "k = ", k);
  
  // q = &p; compiles with a warning because assigning int * from int ** (effectively &&i)

  // *q = &j; compiles with a warning because assigning to an int from a int *
  
  // i = (*&)j; fails to compile with error expected expression before ')' token 

  i = *&*&j; // compiles without warning since effectively a circular reference
  printf("%s%d\n", "i = ", i);

  q = &j;
  i = *p++ + *q;
  printf("%s%d\n", "i = ", i); // compiles without warning and in this case prints 10

  return EXIT_SUCCESS;
}
