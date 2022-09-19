#include <stdio.h>
#include <stdlib.h>

int
gfclose(FILE *stream)
{
  if (fclose(stream) == EOF) {
    fprintf(stderr, "Falied to close - bye.");
    exit(1);
  }
  return 0;
}
