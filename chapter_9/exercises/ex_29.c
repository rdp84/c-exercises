
#include <stdio.h>
#include <stdlib.h>

#if (VAX || PC)
  #define HEX0 0x6c6c6548
  #define HEX1 0x77202c6f
  #define HEX2 0x646c726f
  #define HEX3 0x00000a21
#else
  #define HEX0 0x48656c6c
  #define HEX1 0x6f2c2077
  #define HEX2 0x6f726c64
  #define HEX3 0x210a0000
#endif

/*
  #define HEX0 0x48656c6c
  #define HEX1 0x6f2c2077
  #define HEX2 0x6f726c64
  #define HEX3 0x210a0000
*/

/* 
   HEX0 = Hell 
   HEX1 = o, w
   HEX3 = orld
   HEX4 = !\n
*/


/* 
   Declaration causes 128-bits of shared memory to be assigned for the members
   of the union
*/
typedef union {

  char what[16];
  /* 
     The textbook uses long but for me a long is 64-bits so doesn't work too
     well:
     long cipher[4];
   */

  int cipher[4];
} mystery;



int main(void)
{
  int i, j;
  mystery x;

  /* 
     If you split each HEX up into pairs of digits, ie., 
     HEX0 = 0x48656c6c = 48 65 6c 6c then each pair is 8 bits long, the length of
     a char. When you intepret the shared memory as a char then this causes the
     int to be divided up into bytes (8-bits) and the corresponding byte to be
     mapped to its ASCII character.

     With longs it doesn't work too well because for a start the char is still
     128 bits long but the long becomes 256. The long declared also contains a
     number of 0 bits since it only need 32 bit to represent the HEX passed in.
     This empty bits get mapped to the end of string sentinel character so when
     we come to print the char array as a string it only contains a portion of it
   */
  
  x.cipher[0] = HEX0;
  x.cipher[1] = HEX1;
  x.cipher[2] = HEX2;
  x.cipher[3] = HEX3;

  /*
  for (i = 0; i < 4; ++i) {
    printf("cipher[%d] = %ld\n", i, x.cipher[i]);
    for (j = (i * 4); j < ((i * 4) + 4); ++j) {
      if (x.what[j] == '\0') x.what[j] = 'X';
      printf("what[%d] = %c\n", j, x.what[j]);
    }
  }
  */

  printf("%s\n", x.what);
  return EXIT_SUCCESS;
}
