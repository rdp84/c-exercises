#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[]);

int
main(void)
{
  char s[] = "hello, world!";
  printf("%s\n", s);
  reverse(s);
  printf("%s\n", s);  

  return EXIT_SUCCESS;
}

/* reverse: reverse string s in place */
void
reverse(char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
