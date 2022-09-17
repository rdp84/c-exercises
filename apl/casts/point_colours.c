#include <stdio.h>
#include <stdlib.h>

struct colour_t {
  float red;
  float green;
  float blue;
};
typedef struct colour_t colour_t;

struct point_t {
  float x;
  float y;
  float z;
};
typedef struct point_t point_t;

int main(void) {
  point_t  *p;
  colour_t *c;

  c = (colour_t *) malloc(sizeof(colour_t));
  
  /* If we hadn't initialised c we'd get a seg. fault here */
  c->red = 0.5;
  c->green = 0.25;
  c->blue = 0.125;
  printf("c->red is: %f\n", c->red);
  printf("c->green is: %f\n", c->green);
  printf("c->blue is: %f\n", c->blue);

  /* point_t and colour_t align so we can cast */
  p = (point_t *) ((void *) c);
  p->x = 0.75;
  printf("p->x is: %f\n", p->x);
  printf("p->y is: %f\n", p->y);
  printf("p->z is: %f\n", p->z);
 
  printf("c->red is: %f\n", c->red);
  printf("c->green is: %f\n", c->green);
  printf("c->blue is: %f\n", c->blue);
  
  return EXIT_SUCCESS;
}
