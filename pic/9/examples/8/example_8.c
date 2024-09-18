#include "unit.h"

/* Can create unit test to make sure bugs do not return */
/* Can now invoke lookup() for user code or lookup_test() to perform the self test */

int main(int argc, char **argv) {
  if (getenv("SELFTEST"))
    lookup_test();
  else
    lookup(argv[1]);

  return 0;
}
