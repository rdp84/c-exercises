
#include <stdio.h>
#include <stdlib.h>

void rotate(int [], int);

int main(void)
{

    int primes[10] = {2,3,5,7,11,13,17,19,23,29};
    printf("In function main. The start addess of the array is %p\n", primes);
    rotate(primes, 10);

    int i;
    for (i = 0; i < 10; ++i)
        printf("%d ", primes[i]);
    putchar('\n');

    rotate(primes, 5);
    for (i = 0; i < 10; ++i)
        printf("%d ", primes[i]);
    putchar('\n');

    return EXIT_SUCCESS;
}

void rotate(int a[], int n)
{
    int i, temp;

    printf("In function rotate. The start address of the array is %p\n", a);

    temp = a[n - 1];
    for (i = n - 1; i > 0; --i)
        a[i] = a[i - 1];
    a[0] = temp;
}
