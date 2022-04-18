/* Test the two-stack Polish evaluation algorithm */

#include "polish.h"

int main(void)
{
  /*
  char  str[] = "2, -, 3, -, -, 4, +, 7, " \
    "+, -1, -, 1, +, *, *";
  */
  char c, str[MAXSTRING];
  int i;
  stack polish;

  printf("Please enter your reverse Polish expression below:\n");
  i = 0;
  while (i < MAXSTRING && (c = getchar()) != '\n') {
    if (!isspace(c)) {
      str[i] = c;
      i++;
    }
  }

  printf("\n%s%s\n\n",
         "Polish expression: ", str);
  fill(&polish, str);         /* fill stack from string */
  prn_stack(&polish);         /* print the stack */
  printf("\n%s%d\n\n",
         "Polish evaluation: ", evaluate(&polish));

  return EXIT_SUCCESS;
}

