#include <stdio.h>
#include <stdlib.h>

struct coord_t {
  int x;
  int y;
};
typedef struct coord_t coord_t;

int
main(void)
{
  coord_t *p1, *p2;

  /* Allocate and use p1 */
  p1 = (coord_t *) malloc(sizeof(coord_t));
  p1->x = 256;
  p1->y = 512;
  printf("p1->x is %i\n", p1->x);
  printf("p1->y is %i\n", p1->y);

  /* Deallocate */
  free(p1);

  /* Erroneous attempt to use p1 after deallocation */
  printf("p1->x is %i\n", p1->x);
  printf("p1->y is %i\n", p1->y);

  p2 = (coord_t*) malloc(sizeof(coord_t));
  printf("p2->x is %i\n", p2->x);
  printf("p2->y is %i\n", p2->y);  

  p2->x = 1024;

  /* Erroneous attempt to use p1 after deallocation */
  printf("p1->x is %i\n", p1->x);
  printf("p1->y is %i\n", p1->y);
  
  free(p2);
  return EXIT_SUCCESS;
}
