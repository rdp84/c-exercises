
#include "fruit.h"

#undef  FRUIT
#define FRUIT "blueberry"

int main(void)
{
  printf("I really like %s pie\n", FRUIT);
  return EXIT_SUCCESS;
}
