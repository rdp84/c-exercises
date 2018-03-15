
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = NULL, a;
    printf("Initially p has address %p\n", p);

    int r[10] = {2,3,5,7,11,13,17,19,23,29};

    p = &a;
    printf("After initialisation p has address %p\n", p);

    *p = 6;
    r[6] = 4;

    printf("r points to the address %p\n", r);
    printf("p points to the address %p\n", p);
    printf("a has value %d\n", a);

    p = r;

    printf("r points to the address %p\n", r);
    printf("p points to the address %p\n", p);

    p = (r + 3);
    printf("p points to the address %p\n", p);

    int i;
    for (i = 0; i < 10; i++)
        printf("&p[%d] = %p, p[%d] = %d\n", i, &p[i], i, p[i]);

    return EXIT_SUCCESS;
}
