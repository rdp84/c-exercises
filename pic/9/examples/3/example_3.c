#include <netdb.h>
#include <stdio.h>

/* Tips on debug printing: */
/* - put in as much information as you can to help gather information in the future */
/* - make each entry as uniques as possible so that you can tie the ouput back to the source code */
/* - flush the debug output so that it reliably appears in the terminal */
int main(int argc, char **argv) {
  int i;
  struct hostent *hp;

  printf("%s:%2d argc: %d\n", __FILE__, __LINE__, argc);
  for (i = 1; i < argc; i++) {
    hp = gethostbyname(argv[i]);
    printf("%s:%2d hp: %p\n", __FILE__, __LINE__, hp);
    fflush(stdout);
    printf("%s:%2d %s\n", __FILE__, __LINE__, hp->h_name);
    fflush(stdout);
  }
  return 0;
}
