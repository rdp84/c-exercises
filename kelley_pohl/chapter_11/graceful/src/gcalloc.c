#include <stdio.h>
#include <stdlib.h>

void *
gcalloc(int n, unsigned int sizeof_something)
{
  void *p;

  if ((p = calloc(n, sizeof_something)) == NULL) {
    fprintf(stderr, "\nERROR: calloc() failed - bye.\n\n");
    exit(1);
  }
  return p;
}
