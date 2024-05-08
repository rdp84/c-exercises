#include <stdio.h>

int a = 2;
unsigned char b = 'A';
extern int alpha;

int
main(void)
{
  extern unsigned char b;
  //  extern int a;  
  // double a = 3.4;
  // int a = 3;

  {
    extern int a;
    printf("%d %d\n", b, a+1);
  }

  return 0;
}
