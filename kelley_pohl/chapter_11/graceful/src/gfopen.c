#include <stdio.h>
#include <stdlib.h>

FILE *
gfopen(char *filename, char *mode)
{
  FILE *fp;

  if ((fp = fopen(filename, mode)) == NULL) {
    fprintf(stderr, "Cannot open %s - bye.", filename);
    exit(1);
  }
  return fp;
}
