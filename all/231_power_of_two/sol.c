#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;
    }

    /* As we check n is negative before, (n - 1) won't cause underflow. */
    return 0 == (n & (n - 1));
}
