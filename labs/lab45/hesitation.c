
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

double mytime(void);

int main(void)
{
    int number1, number2, answer;
    double start, end;

    srand((int) time(NULL));
    number1 = rand() % 100;
    number2 = rand() % 100;

    printf("What is %d * %d?\n", number1, number2);
    start = mytime();
    scanf("%d", &answer);

    while (answer != (number1 * number2)) {

        printf("Incorrect answer. Please try again.\n");
        scanf("%d", &answer);
    }

    end = mytime();
    printf("Correct answer. That took you %.2f seconds to work out\n", end - start);

    return EXIT_SUCCESS;
}

double mytime(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec/1E6;
}
