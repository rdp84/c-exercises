#include <stdio.h>
#include <stdlib.h>

struct colour_t {
  float red;
  float green;
  float blue;
};
typedef struct colour_t colour_t;

struct color_t {
  float cyan;
  float magenta;
  float yellow;
  float key;
};
typedef struct color_t color_t;


/*
  Program compiles without errors. It also runs without errors.
  However it has an undetected memory access (c0->key)
  To detect it need to run it through valgrind
 */
int main(void) {
  color_t *c0;
  colour_t *c;

  c = (colour_t *) malloc(sizeof(colour_t));
  c->red = 0.5;
  c->green = 0.25;
  c->blue = 0.125;

  c0 = (color_t *) ((void *) c);
  printf("c0->cyan is %f\n", c0->cyan);
  printf("c0->magenta is %f\n", c0->magenta);
  printf("c0->yellow is %f\n", c0->yellow);
  printf("c0->key is %f\n", c0->key);

  free(c);
  return EXIT_SUCCESS;
}
