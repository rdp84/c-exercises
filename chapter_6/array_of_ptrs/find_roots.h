
#include <assert.h>
#include <math.h>
#include <stdio.h>

#define N 4

typedef double dbl;

/* Create the type "ptr to fct taking a double and returning a dbl */
typedef dbl (*pfdd)(dbl);

extern int cnt;
extern const dbl eps; /* epsilon, a small quantity */

dbl bisection(pfdd f, dbl a, dbl b);
dbl f1(dbl x);
dbl f2(dbl x);
dbl f3(dbl x);
