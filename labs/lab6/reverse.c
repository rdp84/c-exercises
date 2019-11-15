
#include <stdio.h>
#include <stdlib.h>

void reverse(int [], int);

int main(void)
{

    int primes[10] = {2,3,5,7,11,13,17,19,23,29};
    printf("In function main. The start addess of the array is %p\n", primes);
    reverse(primes, 10);

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
    int i, temp;

    printf("In function reverse. The start address of the array is %p\n", a);

    for (i = 0; i < n / 2; i++) {
      temp = a[n - 1 - i];
      a[n - 1 - i] = a[i];
      a[i] = temp;
    }
}
