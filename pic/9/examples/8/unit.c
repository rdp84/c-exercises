#include "unit.h"

void lookup(char *buf) {
  struct hostent *hp;

  /* Poor interface since it terminates the entire program, needs improving */
  assert(buf != NULL);

  hp = gethostbyname(buf);
  printf("%s -> %s\n", buf, hp ? hp->h_name : "unknown");
}

void lookup_test(void) {
  /* Manually written to enumerate the allowable inputs, how can coverage be improved */
  lookup("google.com");
  lookup("doesnotexist.abc");
  lookup("");
  lookup(NULL);
}
