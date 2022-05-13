#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char []);

int
main(void)
{
  char s[] = "hello, world!";
  printf("%s\n", s);
  reverse(s);
  printf("%s\n", s);
  return EXIT_SUCCESS;
}

/* reverse: recursive function to reverse s in place */
void
reverse(char s[])
{
  static int i;
  int        j, c;

  j = strlen(s) - (i + 1);
  
  if (i < j) {
    c = s[i];
    s[i++] = s[j];
    s[j] = c;

    reverse(s);
  }
}
