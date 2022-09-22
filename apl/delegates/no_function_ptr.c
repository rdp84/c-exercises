#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Macro to test for string equality */
#define STREQ(a, b)  (strcmp((a), (b)) == 0)

int  non_null(char *, int);
void print(char *[], int);

/* Function to use as a filter, has additional int argument */
int non_null(char *s, int n) {
  return !STREQ(s, "");
}

/*
  We don't use a function pointer here now and so this is
  error'd by the compiler - to few arguments to non_null
 */
void print(char *strings[], int n) {
  int count, i;

  for(count = i = 0; i < n; i++)
    if (non_null(strings[i])) /* Error here! */
      printf("Item %d is '%s'\n", count++, strings[i]);
}

/*
  It is the use of function pointers in the previous programs
  which causes C to accept this level of mismatch betweem formal
  and actual parameters.
  Not using them causes this program to be faulted by the compiler
 */
int main(void) {
  char *strings[4] = { "", "abc", "", "def" };
  print(strings, 4);

  return EXIT_SUCCESS;
}
