
#include <stdio.h>
#include <stdlib.h>

#define TRY_ME
void print_try_me_status(void);

int main(void)
{
  /* 
     The undef directive completely blitzs TRY_ME; when the call is made to the
     print function then it prints TRY_ME is not defined on each occassion.

     No compiler warnings are produced TRY_ME is not defined anywhere and
     you try and undefine it
  */

  print_try_me_status();
#undef TRY_ME
  print_try_me_status();
  
  return EXIT_SUCCESS;
}


void print_try_me_status(void)
{
#ifdef TRY_ME
  printf("TRY_ME is defined!\n");
#else
  printf("TRY_ME is not defined\n");
#endif
}
