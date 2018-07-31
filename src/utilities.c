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

    srand (time (NULL));
    return (rand () % (high - low)) + low;

}