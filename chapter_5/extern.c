
#include <stdio.h>
#include <stdlib.h>

int a = 1, b = 2, c = 3;
int f(void);

int main(void)
{
    printf("%3d\n", f());
    printf("%3d%3d%3d\n", a, b, c);

    return EXIT_SUCCESS;
}

int f(void)
{
    int b, c;
    a = b = c = 4;
    return (a + b + c);
}
