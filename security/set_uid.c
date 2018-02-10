
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

static uid_t euid, uid;

int main(int argc, char *argv[])
{

  uid = getuid();
  euid = geteuid();

  printf("The real user ID is %d\n", uid);
  printf("The effective user ID is %d\n", euid);

  FILE *file;
  
  seteuid(uid);
  printf("The effective user ID is now %d\n", geteuid());
  
  seteuid(euid);
  printf("The effective user ID is now %d\n", geteuid());
  file = fopen("/root/blah.txt", "a");

  seteuid(uid);
  printf("The effective user ID is now %d\n", geteuid());

  fprintf(file, "Someone used this program\n");
  fclose(file);

  return 0;
}
