#include <netdb.h>
#include <stdio.h>
#include <assert.h>

/* Original program in example_1.c without assertions will crash */
/* Running with assertions results in a much more friendly error message */
/* Assertions can be disabled by defining the NDEBUG preprocessor flag */
/* e.g., gcc -Wall -DNDEBUG .... */

int main(int argc, char **argv) {
  struct hostent *hp;
  hp = gethostbyname("doesnotexist.abc");
  assert(hp != NULL);
  printf("%s\n", hp->h_name);
  return 0;
}
