
#include "bits.h"

int main(void)
{
  /*
     3 members of word will share 1 word (32-bits) of memory.
     This initialization will set it to 0.
   */
  word w = {0};

  /* Set bit number 8 to 1 */
  w.bit.b8 = 1;
  /* Set byte b0 to 'a' */
  w.byte.b0 = 'a';

  /*
     After two above assignments the 32-bits now look like:
     00000000 00000000 00000001 01100001

     w.bit.b8   = 00000000 00000000 00000001 00000000
     w.byte.b0  = 00000000 00000000 00000000 01100001
   */

  /* Will print 353 = 256 + 64 + 32 + 1 */
  printf("w.i = %d\n", w.i);
  bit_print(w.i);

  return EXIT_SUCCESS;
}

void bit_print(int a)
{
  int i;
  int n = sizeof(int) * CHAR_BIT;
  int mask = 1 << (n - 1);

  for(i = 1; i <= n; ++i) {
    putchar((a & mask) ? '1' : '0');
    a <<= 1;
    if (i % CHAR_BIT == 0 && i < n)
      putchar(' ');
  }
  putchar('\n');
}
