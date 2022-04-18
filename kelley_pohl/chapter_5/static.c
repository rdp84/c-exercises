
#include <stdio.h>
#include <stdlib.h>

void f(void);

int main(void)
{
    int i;
    for (i = 0; i < 10; i++)
        f();

    return EXIT_SUCCESS;
}

void f(void)
{
    static int cnt = 0;

    ++cnt;
    if (cnt % 2 == 0)
        printf("cnt mod 2 is zero: %d\n", cnt);
    else
        printf("cnt mod 2 is non-zero: %d\n", cnt);
}
