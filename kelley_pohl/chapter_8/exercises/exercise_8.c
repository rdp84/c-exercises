
#include <stdio.h>
#include <ctype.h> // contains isalpha macro and function

int main(void)
{
  // Pre-processor doe not recgonise (isaplpha) but
  // compiler recognises it as a function call
  if((isalpha)('a'))
    printf("Found the isalpha() function!\n");
}
