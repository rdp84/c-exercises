
#include <stdlib.h>
#include <stdio.h>
#include "descartes.h"

int main(void)
{    

    point_t p, q, r, s;
    double diagonal, width, height;

    OpenGraphics();

    printf("Indicate a single vertex of the rectangle by clicking left mouse button.\n");
    p = GetPoint();

    printf("Indicate opposing vertex of the rectangle by clicking left mouse button.\n");
    r = GetPoint();

    s = Point(XCoord(p), YCoord(r));
    q = Point(XCoord(r), YCoord(p));

    DrawLineSeg(LineSeg(p, s));
    DrawLineSeg(LineSeg(s, r));
    DrawLineSeg(LineSeg(r, q));
    DrawLineSeg(LineSeg(q, p));

    diagonal = Length(LineSeg(p, r));
    height = Length(LineSeg(p, s));
    width = Length(LineSeg(r, s));

    printf("The diagonal of the rectangle has length: %.2f\n", diagonal);
    printf("Height of the rectangle is: %.2f\n", height);
    printf("Width of the rectangle is: %.2f\n", width);

    if (height >= 1.25 * width)
        printf("The rectangle that has been drawn is tall\n");
    else if (width >= 1.25 * height)
        printf("The rectangle that has been drawn is wide\n");
    else
        printf("The rectangle that has been drawn is almost square\n");

    CloseGraphics();
    return EXIT_SUCCESS;
}
