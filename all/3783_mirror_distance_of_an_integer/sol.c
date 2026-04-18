#include <stdlib.h>

static int computeReversedValue(int x) {
    int reversed_x = 0;

    while (x > 0) {
        reversed_x = ((reversed_x * 10) + (x % 10));
        x /= 10;
    }

    return reversed_x;
}

int mirrorDistance(int n) {
    return abs(n - computeReversedValue(n));
}
