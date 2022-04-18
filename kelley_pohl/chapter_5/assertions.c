
#include <assert.h>
#include <stdio.h>
#include<stdlib.h>

int g(int);

int main(void)
{
    int a = -7;

    printf("Before the assert\n");
    assert(g(a) > 0);
    printf("After the assert\n");
}

int g(int a)
{
    if (a > 0)
        return a;
    else
        return a;
}
