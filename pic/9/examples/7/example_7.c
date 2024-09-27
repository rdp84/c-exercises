#include <netdb.h>
#include <stdio.h>
#include <assert.h>

/*
 * Assertions are convenient but they do not scale to larger programs
 * Would be useful to
 * - observer the value of a C variable during program execution
 * - stop the execution of the program if an assertion is violated
 * - get a trace of the function calls leading up to a failure
 *
 * These features are provided by debuggers, of which there are two classes
 * - interpretive debuggers work by simulating program execution one statement at a timeout
 * - direct execution debuggers that use hardware and OS features to inspect the program memory
 *   and set breakpoints to pause execution
 */
int main(int argc, char **argv) {
  struct hostent *hp;

  assert(argv[1] != NULL);
  hp = gethostbyname(argv[1]);

  assert(hp != NULL);
  printf("%s\n", hp->h_name);

  return 0;
}
