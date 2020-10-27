
#include <stdio.h>
#include <stdlib.h>

typedef struct { unsigned a:1, :0, b:1; } a;
typedef struct { unsigned a:1, b:1; } b;

int main(void)
{

  /*
    Below statement will print 2.0 

    sizeof(a) is 2 words (8-bytes); the unanmed bit field
    with zero width causes alignment to the next word

    sizeof(b) is 1 word (4-bytes)

    Therefore 8 / 4 = 2.
  */
  printf("%.1f\n", (float) sizeof(a) / sizeof(b));
  return EXIT_SUCCESS;
}
