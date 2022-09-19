#include <stdio.h>
#include <stdlib.h>

#include "glib.h"

int
main(void)
{
  FILE *ofp;

  ofp = gfopen("outfile", "w+");
  fprintf(ofp, "Hello World\nWhat a nice day it is\n");
  gfclose(ofp);

  return EXIT_SUCCESS;
}
