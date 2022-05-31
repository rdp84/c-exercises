#include "alloc.h"

#define P1SIZE  10
#define P2SIZE  5
#define P3SIZE  3

void fill_pointer(char *, char, int);
void print_pointer(char *, int);

int
main(void)
{
  char *p1, *p2, *p3;

  p1 = alloc(P1SIZE);
  p2 = alloc(P2SIZE);
  p3 = alloc(P3SIZE);

  fill_pointer(p1, 'a', P1SIZE);
  fill_pointer(p2, 'b', P2SIZE);
  fill_pointer(p3, 'c', P3SIZE);

  printf("p1: ");
  print_pointer(p1, P1SIZE);

  printf("p2: ");
  print_pointer(p2, P2SIZE);

  printf("p3: ");
  print_pointer(p3, P3SIZE);

  afree(p3);
  afree(p2);
  afree(p1);
  
  return EXIT_SUCCESS;
}

void
fill_pointer(char *s, char c, int limit)
{
  while (limit-- > 0)
    *s++ = c;
  s -= limit;
}

void
print_pointer(char *s, int limit)
{
  while(limit-- > 0)
    putchar(*s++);
  putchar('\n');
  s -= limit;
}

