#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Macro to test for string equality */
#define STREQ(a, b)  (strcmp((a), (b)) == 0)

int non_null(char *);
void print(char *[], int, int (*f)(char *));

/* Function to use as a filter */
int non_null(char *s) {
  return !STREQ(s, "");
}

/* Delegates are passed as function pointers */
void print(char *strings[], int n, int (*f)(char *)) {
  int count, i;

  for(count = i = 0; i < n; i++)
    if (f(strings[i])) /* call function: can use (*f) */
      printf("Item %d is '%s'\n", count++, strings[i]);
}

int main(void) {
  char *strings[4] = { "", "abc", "", "def" };
  print(strings, 4, non_null); /* delegate */

  return EXIT_SUCCESS;
}
