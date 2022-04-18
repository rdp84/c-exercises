
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    double x = 123.45123451234512345;
    double y = 123.45123451234510789;

    // Print to 17 decimal places
    // Doubles are only accurate to around 15 decimal places

    // We'd expect 123.451234512345123 to at least be printed, anything after that could be arbitary 123.451234512345123xx
    // What we actually see is 123.45123451234512xxx
    // Therefore to get two different numbers we will need 123.45123451234510000


    printf("%.17f\n%.17f\n", x, y);
    return EXIT_SUCCESS;
}
