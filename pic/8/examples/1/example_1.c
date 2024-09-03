#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BIG_NUMBER   10000000

typedef void (*increment)(int *);

void run_increment(void (*)(int *), int *, char *);
void increment_every(int *);
void increment_eighth(int *);
void increment_sixteenth(int *);

int main(void)
{
  int *array;
  char *msg;

  array = malloc(sizeof(int) * BIG_NUMBER);
  msg = "increment_every";
  run_increment(increment_every, array, msg);
  free(array);

  array = malloc(sizeof(int) * BIG_NUMBER);
  msg = "increment_eighth";
  run_increment(increment_eighth, array, msg);
  free(array);

  array = malloc(sizeof(int) * BIG_NUMBER);
  msg = "increment_sixteenth";
  run_increment(increment_sixteenth, array, msg);
  free(array);

  return 0;
}

void run_increment(increment f, int *array, char *msg) {
  clock_t start, end, diff;

  start = clock();
  (*f)(array);
  end = clock();
  diff = end - start;
  printf("%s: %ld microseconds\n", msg, diff);
}

void increment_every(int *array) {
  int i;

  for (i = 0; i < BIG_NUMBER; i += 1) {
    array[i] = 0;
  }
}

void increment_eighth(int *array) {
  int i;

  for (i = 0; i < BIG_NUMBER; i += 8) {
    array[i] = 0;
  }
}

void increment_sixteenth(int *array) {
  int i;

  for (i = 0; i < BIG_NUMBER; i += 16) {
    array[i] = 0;
  }
}
