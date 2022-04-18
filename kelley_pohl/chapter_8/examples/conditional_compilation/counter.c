
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  printf("Entering the boring loop\n");

  // The loop contains comments so we can't simply comment it out with the
  // /* ... */ operator

  // Instead us #if 0 ... #endif to compile it out

  #if 0
  int i= 0;
  while (i < 10) {
    /* This is a very boring loop */

    // print the value of i
    printf("i = %d\n", i);

    //increment i
    ++i;
  }
  #endif

  printf("Finished the boring loop\n");

  return EXIT_SUCCESS;
}
