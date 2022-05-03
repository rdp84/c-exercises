#include <stdio.h>
#include <stdlib.h>

int  my_rand(void);
void my_srand(unsigned int seed);

unsigned long int next = 1;

int
main(void)
{
  char c;

  my_srand(7);
  while ((c = getchar()) != EOF)
    if (c == '\n')
      printf("%d\n", my_rand());

  return EXIT_SUCCESS;
}

/* my_rand: return pseudo-random integer on 0..32767 */
int
my_rand(void)
{
  next = next * 1103515245 + 12345;
  return (unsigned int)(next / 65536) % 32768;
}

/* my_srand: set seed for rand() */
void
my_srand(unsigned int seed)
{
  next = seed;
}
