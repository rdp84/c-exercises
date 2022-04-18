
#include <stdio.h>

/* 
   Union declaration contains a duplicate member, 'a'. 
   Therefore a compiler error will be thrown.
*/
union a {
  int   a;
  char  b;
  float a;
} a, b, c;

void print_union(union a);

int main(void)
{
  return 0;
}




