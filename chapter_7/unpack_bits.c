
#include "bits.h"

char unpack(int p, int k) /* k = 0, 1, 2 or 3 */
{
  int n = k * CHAR_BIT; /* n = 0, 8, 16 or 24 */
  unsigned mask = 255; /* 00000000 00000000 00000000 11111111 */

  mask <<= n;
  return ((p & mask) >> n);
}
