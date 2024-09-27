#include <netdb.h>
#include <stdio.h>

int main(int argc, char **argv) {
  struct hostent *hp;
  hp = gethostbyname("doesnotexist.abc");
  /* results in a segmentation fault, NULL pointer */
  printf("%s\n", hp->h_name);
  return 0;
}
