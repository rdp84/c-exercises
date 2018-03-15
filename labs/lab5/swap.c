
#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);
void swap_wrong(int, int);

int main(void)
{
    int i = 1, j = 2, option;
    printf("In main. i is stored at %p, j is stored at %p\n\n", &i, &j);

    printf("Please enter 0 if you'd like to use swap_wrong or 1 for swap\n");
    scanf("%d", &option);

    if (option == 0)
        swap_wrong(i, j);
    else if (option == 1)
        swap(&i, &j);
    else {
        printf("Invalid option entered. Please run again\n");
        return EXIT_FAILURE;
    }

    printf("i = %d, j = %d\n", i, j);
    return EXIT_SUCCESS;
}

void swap(int *aptr, int *bptr)
{
    printf("\nIn swap. aptr is %p, bptr is %p\n\n", aptr, bptr);
    int tmp;

    tmp = *aptr;
    *aptr = *bptr;
    *bptr = tmp;
}

void swap_wrong(int a, int b)
{
    printf("\nIn swap_wrong. a is stored at %p, b is stored at %p\n\n", &a, &b);
    int tmp;

    tmp = a;
    a = b;
    b = tmp;
}
