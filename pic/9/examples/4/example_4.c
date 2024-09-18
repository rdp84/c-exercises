#include <netdb.h>
#include <stdio.h>

/* Source code can become very ugly and littered with debugging statements */
/* C preprocessor comes to the rescue: */
/* - define a DEBUG parameter to compile your program with */
/* - #define a debug printf that only runs if DEBUG is non-zero */
/* - disabling DEBUG means debugging calls with be optimised away at compile time */

#ifndef DEBUG
#define DEBUG 1
#endif

#define debug_printf(fmt, ...) \
  do { \
    if (DEBUG) { \
      fprintf(stdout, fmt, __VA_ARGS__); \
      fflush(stdout); \
    } \
  } \
  while (0)

int main(int argc, char **argv) {
  int i;
  struct hostent *hp;

  debug_printf("%s:%2d argc: %d\n", __FILE__, __LINE__, argc);
  for (i = 1; i < argc; i++) {
    hp = gethostbyname(argv[i]);
    debug_printf("%s:%2d hp: %p\n", __FILE__, __LINE__, hp);
    debug_printf("%s:%2d %s\n", __FILE__, __LINE__, hp->h_name);
  }
  return 0;
}
