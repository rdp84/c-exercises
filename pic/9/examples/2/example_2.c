#include <netdb.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int i;
  struct hostent *hp;

  printf("argc: %d\n", argc);
  for (i = 1; i < argc; i++) {
    hp = gethostbyname(argv[i]);
    printf("hp: %p\n", hp);
    if (hp)
      printf("%s\n", hp->h_name);
  }
}
