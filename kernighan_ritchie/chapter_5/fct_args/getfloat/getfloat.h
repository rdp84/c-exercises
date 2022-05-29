#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFSIZE    100
#define ARRAYSIZE  4

extern char    buf[];
extern int     bufp;
extern double  array[];

int  getch(void);
void ungetch(int);
int  getfloat(double *);
