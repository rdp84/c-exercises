
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

int main(void)
{
  int i = 0;

  #if DEBUG
  ++i;
  printf("debug: i = %d\n", i); 
  #endif

  printf("i = %d\n", i);
  
  return EXIT_SUCCESS;
}
