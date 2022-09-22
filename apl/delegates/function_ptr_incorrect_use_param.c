#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length_is(char *, int);
void print(char *[], int, int (*f)(char *));

/*
  Function to use as a filter, has additional int argument
  which we attempt to make use of
 */
int length_is(char *s, int n) {
  printf("Checking if \"%s\" has length %d\n", s, n);
  return strlen(s) == n;
}

/* Delegates are passed as function pointers */
void print(char *strings[], int n, int (*f)(char *)) {
  int count, i;

  for(count = i = 0; i < n; i++)
    if (f(strings[i])) /* call function: can use (*f) */
      printf("Item %d is '%s'\n", count++, strings[i]);
}

/*
  Will generate a compiler warning, about length_is having an additional
  argument and not matching int (*f)(char *)
  We make use of the missing parameter, so in effect use an unitialised
  variable which leads to unpredicatble results
 */
int main(void) {
  char *strings[4] = { "", "abc", "", "def" };
  print(strings, 4, length_is); /* delegate */

  return EXIT_SUCCESS;
}
