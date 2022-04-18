
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

  char c = 'A';
  char d;

  printf("sizeof(c)       = %u\n", sizeof(c)); // print 1
  printf("sizeof('A')     = %u\n", sizeof('A')); // print 4
  printf("sizeof(c + c)   = %u\n", sizeof(c + c)); // print 4
  printf("sizeof(d = 'A') = %u\n", sizeof(d = 'A')); // print 1
  
  return EXIT_SUCCESS;
}
