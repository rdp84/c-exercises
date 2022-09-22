#include <stdio.h>
#include <stdlib.h>

struct vector_t {
  float values[1000];
};
typedef struct vector_t vector_t;

int
main(void)
{
  vector_t *v;

  for (;;)
    v = (vector_t *) malloc(sizeof(vector_t));

  return EXIT_SUCCESS;
}
