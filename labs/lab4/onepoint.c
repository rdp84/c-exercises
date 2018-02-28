
#include <stdio.h>
#include <stdlib.h>
#include "descartes.h"

int main(void)
{
    point_t p;

    OpenGraphics();

    p = GetPoint();
    printf("You clicked at the point (%d, %d).\n", XCoord(p), YCoord(p));

    CloseGraphics();
    return EXIT_SUCCESS;
}
