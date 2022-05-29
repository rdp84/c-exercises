#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define NUMBER   '0'
#define MAXOP    100  /* max size of operand */
#define MAXVAL   100  /* maximum depth of val stack */
#define BUFSIZE  100  /* max size of ungetch buffer */

extern int sp;        /* next free stack position */
extern double val[];  /* value stack */
extern char buf[];    /* buffer for ungetch */
extern int bufp;      /* next free positon in buf */

void   push(double);
double pop(void);
void   clear(void);
int    getop(char []);
int    getch(void);
void   ungetch(int);
