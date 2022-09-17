#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

/*
  a structure of SIZE floats
*/
struct vector_t {
  float values[SIZE];
};
typedef struct vector_t vector_t;

float
min(vector_t v)
{
  float x;
  int   i;

  x = v.values[0];
  for (i = 1; i < SIZE; i++)
    if (v.values[i] < x)
      x = v.values[i];

  return x;
}

/*
  This function has a rather artificial space leak which occurs
  only because we allocate the local vector dynamically using
  a call to malloc
*/
float
biased_rnd()
{
  vector_t *v;
  int      i;

  v = (vector_t *) malloc(sizeof(vector_t));
  for (i = 0; i < SIZE; i++)
    v->values[i] = (float) rand(); /* will prduce same sequence of random numbers */

  return min(*v);
  /* space leak: we've forgotten to free v! */
}

float
biased_rnd_free()
{
  vector_t *v;
  int      i;
  float    ret;

  v = (vector_t *) malloc(sizeof(vector_t));
  for (i = 0; i <= SIZE; i++)
    v->values[i] = (float) rand(); /* off-by-one error */

  ret = min(*v);
  free(v); /*remembered to free v so no space leak here */

  return ret;
}

float
biased_rnd_stack()
{
  vector_t v; /* allocated on the stack this time so no need to call malloc */
  int      i;

  for (i = 0; i < SIZE; i++)
    v.values[i] = (float) rand();

  return min(v);
}


/*
  Compile and run with:

  gcc -Wall -g -o leak space_leak.c
  valgrind -s --leak-check=full ./leak

  This should provide detailed information on the space leak and the off-by-one error
 */
int
main(void)
{
  printf("Biased random number (least of 1000): %.3f\n", biased_rnd());
  printf("Biased random number (least of 1000): %.3f\n", biased_rnd_free());
  printf("Biased random number (least of 1000): %.3f\n", biased_rnd_stack());
  return EXIT_SUCCESS;
}
