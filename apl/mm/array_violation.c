#include <stdio.h>
#include <stdlib.h>
#include <mcheck.h>

typedef enum mcheck_status mcheck_status;

void
abort_fn(mcheck_status status)
{
  printf("mcheck_status: %i\n", status);
  switch (status) {
  case MCHECK_OK:
    printf("OK!\n");
    break;
  case MCHECK_FREE:
    printf("Block freed twice!\n");
    break;
  case MCHECK_HEAD:
    printf("Memory before the block was clobbered!\n");
    break;
  case MCHECK_TAIL:
    printf("Memory after the block was clobbered!\n");
    break;
  default:
    printf("Unknown status!\n");
  }
}

/*
  We can ask malloc to check the consistency of dynamic memory by using the mcheck
  function and preloading the malloc debug library libc_malloc_debug.so.0 using the
  LD_PRELOAD environment variable, e.g., LD_PRELOAD=libc_malloc_debug.so.0 ./prog

  There are alternatives to using mcheck if that is difficult

  1. Link with mcheck at compile time and this will implicitly add a mcheck(NULL)
     call. NULL will invoke a generic error handler, printing a message to stderr
     and aborting.

     gcc -Wall -o prog -lmcheck array_violation.c
     LD_PRELOAD=libc_malloc_debug.so.0 ./prog

  2. Set environment variable MALLOC_CHECK_ to a non zero value less than 4.
     0 - checking is enabled but all errors are silently ignored
     1 - on error, a diagnostic message is printed to stderr
     2 - on error, abort is called without a message
     3 - abort is called and a message is printed to stderr

     gcc -Wall -o prog array_violation.c
     MALLOC_CHECK_=1 LD_PRELOAD=libc_malloc_debug.so.0 ./prog
 */
int
main(void)
{
  /* Need to call mcheck before any allocation has been made */
  if (mcheck(abort_fn) != 0) {
    fprintf(stderr, "mcheck() failed\n");
    exit(EXIT_FAILURE);
  }
  int *squares, i;
  squares = (int *) malloc(4 * sizeof(int));

  for (i = 0; i <= 4; i++)
    squares[i] = i * i;        /* off-by-one error */
  for (i = 0; i <= 4; i++)
    printf("%i\n", squares[i]);

  free(squares);

  exit(EXIT_SUCCESS);
}
