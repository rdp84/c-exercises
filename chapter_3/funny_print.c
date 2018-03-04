
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

  // We're not actually adding integers here and rather long integers.
  // The problem is the '1' is similar to 'l' making debugging difficult. 
  printf("Why is 21 + 31 equal to %d\n", 2l + 3l);

  return EXIT_SUCCESS;
}
