#include <netdb.h>
#include <stdio.h>

/* Common approach to debugging is via printing values as the */
/* program executes */
int main(int argc, char **argv) {
  int i;
  struct hostent *hp;

  printf("argc: %d\n", argc);
  for (i = 1; i < argc; i++) {
    hp = gethostbyname(argv[i]);
    printf("hp: %p\n", hp);
    /* Can lead to a fix by simply adding a NULL check */
    if (hp)
      printf("%s\n", hp->h_name);
  }
}
