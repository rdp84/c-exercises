#include "alloc.h"

static char allocbuf[ALLOCSIZE]; /* storgae for alloc */
static char *allocp = allocbuf;  /* next free position */

/* alloc: return pointer to n characters */
char *
alloc(int n)
{
  if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
    allocp += n;
    return allocp - n; /* old p */
  } else
    return 0;          /* not enough room */
}

/* free: free storage pointed to by p */
void
afree(char *p)
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}
