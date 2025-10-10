#include "collatz_conjecture.h"
#include <stdio.h>

int steps(int start);

int steps(int start) {
    int loops = 0;
    if (start > 0) {
        while (start > 1) {
            if (start % 2 == 0) {
                start /= 2;
                loops++;
                printf("The number is now %d\n", start);
            } else {
                start *= 3;
                start += 1;
                loops++;
                printf("The number is now %d\n", start);
            }
        }
    return loops;
    }
    else {
        return -1;
    }
}
