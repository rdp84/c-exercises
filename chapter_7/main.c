
#include "bits.h"

int main(void)
{
  
  printf("abcd = ");
  int packed = pack('a', 'b', 'c', 'd'); 
  bit_print(packed);
  putchar(unpack(packed, 0));
  putchar('\n');

  return EXIT_SUCCESS;
}
