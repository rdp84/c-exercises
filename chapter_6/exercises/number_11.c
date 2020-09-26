
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int a[] = {0, 2, 4, 6, 8},
    *p = a + 3; // this is the same as &a[3]

  /* 
     This will print 7 since we dereference the pointer first,
     which gives us 6, and then we add 1 to it
  */
  
  printf("%s%d%s\n%s%d%s\n",
         "a[?]     = ",   *p,     "?",
         "a[? + 1] = ",   *p + 1, "?");

  /* 
     This will print 8 because we perform pointer arithmetic
     and point to the next int before dereferencing this address
  */
  
  printf("%s%d%s\n%s%d%s\n",
         "a[?]     = ",   *p,     "?",
         "a[? + 1] = ",   *(p + 1), "?");

  printf("%s%p\n", "p:    ", p);
  printf("%s%p\n", "*&p:  ", *&p);
  printf("%s%p\n", "&p:   ", &p);
  
  return EXIT_SUCCESS;
}
