
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

  printf("The size of some fundamental types is computed\n\n");
  printf("       char:%3u byte \n", sizeof(char));
  printf("      short:%3u bytes\n", sizeof(short));
  printf("        int:%3u bytes\n", sizeof(int));
  printf("       long:%3u bytes\n", sizeof(long));
  printf("   unsigned:%3u bytes\n", sizeof(unsigned));
  printf("      float:%3u bytes\n", sizeof(float));
  printf("     double:%3u bytes\n", sizeof(double));
  printf("long double:%3u bytes\n", sizeof(long double));

  return EXIT_SUCCESS;
}
