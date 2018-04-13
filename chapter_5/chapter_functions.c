
#include <stdio.h>
#include <stdlib.h>

int factorial(int);

int a = 33;

int main(void)
{
    int b = 77;

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return EXIT_SUCCESS;
}

int factorial(int n)
{
    int i = 1, product;

    for (i = 2; i <= n; ++i)
        product *= i;
    return product;)
}

double absolute_value(double x)
{
    if (x >= 0.0)
        return x;
    else
        return -x;
}
