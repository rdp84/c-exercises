
#include "list.h"

int main(void)
{
  LINK head;
  DATA people[4] = {
    {"Mike", 44, 76}, {"Dave", 36, 82}, {"Jason", 45, 70},
    {"Tim", 41, 80}
  };

  head = create_l(people, 4);
  print_list(head);

  int cnt = count_weight_age(head, 75, 40);
  printf("The number of people above weight %dkg and " \
         "%d years of a age is: %d\n", 75, 40, cnt);

  sort_age(head);
  print_list(head);

  sort_name(head);
  print_list(head);

  return EXIT_SUCCESS;
}
