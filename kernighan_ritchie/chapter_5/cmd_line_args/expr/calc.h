#include <stdio.h>
#include <stdlib.h>   /* for atof() */
#include <math.h>     /* for fmod */
#include <ctype.h>

#define MAXOP   100   /* max size of operand or operator */
#define NUMBER  '0'   /* signal that a number was found */
#define MAXVAL  100   /* maximum depth of val stack */
#define BUFSIZE 100   /* max size of ungetch buffer */

extern int    sp;     /* next free stack position */
extern double val[];  /* value stack */
extern char   buf[];  /* buffer for ungetch */
extern int    bufp;   /* next free position in buf */
extern char   error;  /* signal that an error was found */

void   push(double);
double pop(void);
void   clear(void);
int    getop(char *, char []);
int    getch(void);
void   ungetch(int);








