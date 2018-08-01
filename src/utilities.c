#include <stdlib.h>
#include <time.h>

unsigned int randomInt (unsigned int min, unsigned int max) {

    unsigned int low = 0, high = 0;

    if (min < max) {
        low = min;
        high = max + 1;
    }

    else {
        low = max + 1;
        high = min;
    }

    return (rand () % (high - low)) + low;

}

int clampInt (int value, int min, int max) {

    if (value > max) return max;
    else if (value < min) return min;
    else return value;

}
