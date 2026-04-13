#include <limits.h>
#include <stdlib.h>

static inline int min(const int i1, const int i2) {
    return ((i1 < i2) ? i1 : i2);
}

int getMinDistance(int* nums, int numsSize, int target, int start) {
    int minimum_distance = INT_MAX;

    for (int i = 0; i < numsSize; ++i) {
        if (target != (nums[i])) {
            continue;
        }

        minimum_distance = min(minimum_distance, abs(i - start));
    }

    return minimum_distance;
}
