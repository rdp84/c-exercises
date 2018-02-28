
#include <stdlib.h>
#include <stdio.h>
#include "descartes.h"

int main(void)
{

    point_t p1, p2;
    lineSeg_t line;

    OpenGraphics();

    printf("Indicate starting point of the line by clicking left mouse button.\n");
    p1 = GetPoint();

    printf("Indicate ending point of the line by clicking left mouse button.\n");
    p2 = GetPoint();

    line = LineSeg(p1, p2);
    DrawLineSeg(line);
    printf("Length of the line drawn is: %f.\n", Length(line));

    CloseGraphics();
    return EXIT_SUCCESS;
}
