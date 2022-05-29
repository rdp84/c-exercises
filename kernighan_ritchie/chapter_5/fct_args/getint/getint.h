#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFSIZE    100
#define ARRAYSIZE  4
#define prn(x)     printf(#x ": %d\n", x)

extern char buf[];
extern int  n, bufp, array[];

int  getch(void);
void ungetch(int);
int  getint(int *);
