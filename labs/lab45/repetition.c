
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int first, second, third, fourth, fifth, numbers_entered, entered;;
    first = second = third = fourth = fifth = 0;
    numbers_entered = 1;

    while (numbers_entered <= 5) {

        printf("Please enter a number between 1 and 50? ");
        scanf("%d", &entered);

        if (entered >= 1 && entered <= 50 &&
            entered != first &&
            entered != second &&
            entered != third &&
            entered != fourth &&
            entered != fifth) {

            if (first == 0)
                first = entered;
            else if (second == 0)
                second = entered;
            else if (third == 0)
                third = entered;
            else if (fourth == 0)
                fourth = entered;
            else
                fifth = entered;

            ++numbers_entered;
        }
    }

    printf("The first number entered was %d\n", first);
    printf("The second number entered was %d\n", second);
    printf("The third number entered was %d\n", third);
    printf("The fourth number entered was %d\n", fourth);
    printf("The fifth number entered was %d\n", fifth);

    return EXIT_SUCCESS;
}
