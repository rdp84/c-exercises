#include <stdio.h>

#define BUFSIZE 1024

int main(void) {
  FILE *fp;
  char buffer[BUFSIZE];

  if ((fp=fopen("example_2", "rb")) == 0) {
    perror("fopen error:");
    return 1;
  }

  while(!feof(fp)) {
    int r = fread(buffer, sizeof(char), BUFSIZE, fp);
    fwrite(buffer, sizeof(char), r, stdout);
  }

  fclose(fp);
  return 0;
}
