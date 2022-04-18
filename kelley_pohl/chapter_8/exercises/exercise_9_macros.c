
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{

  int c;
  printf("Clock ticks (macros): %ld\n", clock());

  while ((c = getchar()) != EOF) {
    if (islower(c))
      putchar(toupper(c));
    else if (isupper(c))
      putchar(tolower(c));
    else if (isdigit(c))
      putchar('x');
    else if (isspace(c)) {
      putchar(c);
      putchar(c);
    }
  }

  printf("Clock ticks (macros): %ld\n", clock());
  return EXIT_SUCCESS;
}
