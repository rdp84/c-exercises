
#include <stdio.h>
#include <stdlib.h>

/*
  Using below macro will fail compilation because the
  declaration string a[] ..., b[] will be expanded to

  char * a[] ..., b[]

  which gives a as an array of pointers to the base
  base address of the string and gives b as an array
  of chars.

  Late in the printf statement we attemnpt to print
  the elements of b as strings when in fact the element
  is declared a char.

  To fix it we need to a '*' before the declaration
  of b to ensure the compiler recognises this as
  an array of pointers.

  The typedef works since a & b are declared as a type
  string which is synonymous with char * and therefore
  the expansion is handled correctly without additional
  characters.
*/

#define string char *

//typedef char * string;

int main(void)
{
  string a[] = {"I", "like", "to", "fight"},
    * b[] = {"pinch", "and", "fight"};

  printf("%s %s %s %s %s %s %s\n",
         a[0], a[1], a[2], a[3], b[0], b[1], b[2]);

  return EXIT_SUCCESS;
}
