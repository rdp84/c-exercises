#include <stdio.h>
#include <stdlib.h>

int  *make_counter(void);
void dummy();

int *make_counter() {
  int counter;

  counter = 0;
  return &counter; /* return address of local variable */
}

/* no use of pointers or addreses in this function */
void dummy() {
  int x = 13; /* simple integer variable */
}

int main(void) {
  int *p;

  /*
    results in a segmentation fault now. On older systems may have
    seen 0 and 13 printed
  */
  p = make_counter();
  printf("*p is %d\n", *p);
  dummy();
  printf("*p is %d\n", *p);
  exit(0);
}
