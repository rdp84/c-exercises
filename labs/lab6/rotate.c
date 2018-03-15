
#include <stdio.h>
#include <stdlib.h>

void reverse(int [], int);

int main(void)
{
    int primes[10] = {2,3,5,7,11,13,17,19,23,29};
    int i;
    for (i = 0; i < 10; ++i)
        printf("%d ", primes[i]);
    putchar('\n');

    reverse(primes, 10);
    for (i = 0; i < 10; ++i)
        printf("%d ", primes[i]);
    putchar('\n');

    return EXIT_SUCCESS;
}

void reverse(int a[], int n)
{
    int tmp;
    int split = n / 2;
    int last = n - 1;

    int i;
    for (i = 0; i < split; ++i) {

        tmp = a[i];
        a[i] = a[last - i];
        a[last - i] = tmp;
    }
}
