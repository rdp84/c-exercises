#include <netdb.h>
#include <stdio.h>
#include <assert.h>

/* This program can crash in at least two ways. How can we reproduce both? */
int main(int argc, char **argv) {
  struct hostent *hp;

  /* First crash if we don't provide a command-line argument */
  assert(argv[1] != NULL);
  hp = gethostbyname(argv[1]);

  /* Second crash if we provide an invalid hostname */
  assert(hp != NULL);
  printf("%s\n", hp->h_name);

  return 0;
}
