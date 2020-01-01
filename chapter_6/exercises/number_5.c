
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char a, b, c, *p, *q, *r;

  // Char is 1 byte therefore the addresses of the a, b and c are one after the other
  // with a having the highest address
  
  printf("%s%p\n", "Address of a: ", &a);
  printf("%s%p\n", "Address of b: ", &b);
  printf("%s%p\n", "Address of c: ", &c);

  // Pointers are stored in one machine word which in the case of hme laptop is 8 bytes. Therefore
  // the addresses of the pointers are spearated by 8 bytes.
  
  printf("%s%p\n", "Address of p: ", &p);
  printf("%s%p\n", "Address of q: ", &q);
  printf("%s%p\n", "Address of r: ", &r);

  a = 'a';
  b = 'b';
  c = 'c';

  p = &a;
  q = &b;
  r = &c;

  printf("%s%p\n", "Address of a: ", &a);
  printf("%s%p\n", "Address of b: ", &b);
  printf("%s%p\n", "Address of c: ", &c);

  printf("%s%p\n", "Address of p: ", &p);
  printf("%s%p\n", "Address of q: ", &q);
  printf("%s%p\n", "Address of r: ", &r);
  
  return EXIT_SUCCESS;
}
