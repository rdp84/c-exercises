#include <stdio.h>
#include <stdlib.h>

/* echo command-line arguments: 1st version with array index */
/*
int
main(int argc, char *argv[])
{
  int i;

  for (i = 1; i < argc; i++)
    printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
  printf("\n");

  return EXIT_SUCCESS;
}
*/

/* echo command-line arguments: 2nd version with pointer manipulation */
int
main(int argc, char *argv[])
{
  while (--argc > 0)
    printf("%s%s", *++argv, (argc > 1) ? " " : "");
  printf("\n");

  return EXIT_SUCCESS;
}
