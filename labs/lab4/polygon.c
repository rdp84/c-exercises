
#include <stdio.h>
#include <stdlib.h>
#include "descartes.h"


int main(void)
{

    point_t current, previous, start;
    lineSeg_t edge;
    double perimeter = 0;

    OpenGraphics();

    start = GetPoint();
    current = GetPoint();
    previous = start;

    while (XCoord(current) >= 0) {

        edge = LineSeg(previous, current);
        DrawLineSeg(edge);
        perimeter += Length(edge);

        previous = current;
        current = GetPoint();
    }

    edge = LineSeg(previous, start);
    DrawLineSeg(edge);
    perimeter += Length(edge);

    printf("The perimeter of the polygon was: %.2f\n", perimeter);

    CloseGraphics();
    return EXIT_SUCCESS;
}
