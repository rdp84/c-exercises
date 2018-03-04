
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

  int i = 7;
  int* p = &i;

  printf("%s%d\n%s%p\n", "   Value of i: ", *p,
	 "Location of i: ", p);

  return EXIT_SUCCESS;
}
