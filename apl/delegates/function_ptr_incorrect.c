#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Macro to test for string equality */
#define STREQ(a, b)  (strcmp((a), (b)) == 0)

int non_null(char *, int);
void print(char *[], int, int (*f)(char *));

/* Function to use as a filter, has additional int argument */
int non_null(char *s, int n) {
  return !STREQ(s, "");
}

/* Delegates are passed as function pointers */
void print(char *strings[], int n, int (*f)(char *)) {
  int count, i;

  for(count = i = 0; i < n; i++)
    if (f(strings[i])) /* call function: can use (*f) */
      printf("Item %d is '%s'\n", count++, strings[i]);
}

/*
  Will generate a compiler warning, about non_null having an additional
  argument and not matching int (*f)(char *)
  Because the missing parameter is not used this program runs without
  generating a run-time error
 */
int main(void) {
  char *strings[4] = { "", "abc", "", "def" };
  print(strings, 4, non_null); /* delegate */

  return EXIT_SUCCESS;
}
