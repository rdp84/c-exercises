
#include <stdio.h>
#include <stdlib.h>

// #define DEBUG

int main(void)
{
  int i = 0;

  #ifdef DEBUG
  ++i;
  printf("debug: i = %d\n", i); 
  #endif

  printf("i = %d\n", i);
  
  return EXIT_SUCCESS;
}
