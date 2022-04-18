
#include "list.h"

int main(void)
{
  LINK h1, h2, h3;

  h1 = string_to_list("ABC");
  h2 = string_to_list("EFG");
  h3 = string_to_list("D");

  printf("The resulting h1 list is\n");
  print_list(h1);
  printf("\nThis list has %d elements.\n\n", count(h1));

  printf("The resulting h2 list is\n");
  print_list(h2);
  printf("\nThis list has %d elements.\n\n", count(h2));

  printf("The resulting h3 list is\n");
  print_list(h3);
  printf("\nThis list has %d elements.\n\n", count(h3));

  concatenate(h1, h2);
  printf("The resulting concatenated list is\n");
  print_list(h1);
  printf("\nThis list has %d elements.\n\n", count(h1));

  insert(h1->next->next, h2, h3);
  printf("The resulting inserted list is\n");
  print_list(h1);
  printf("\nThis list has %d elements.\n\n", count(h1));

  delete_list(h1);

  return EXIT_SUCCESS;
}
