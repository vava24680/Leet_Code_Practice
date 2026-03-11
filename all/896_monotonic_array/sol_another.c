#include <stdbool.h>

bool isMonotonic(int* nums, int numsSize) {
    bool is_strictly_monotonic_increasing = false;
    bool is_strictly_monotonic_decreasing = false;

    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] > nums[i - 1]) {
            is_strictly_monotonic_decreasing = true;
        }
        else if (nums[i] < nums[i - 1]) {
            is_strictly_monotonic_increasing = true;
        }

        if (
            is_strictly_monotonic_increasing
            &&
            is_strictly_monotonic_decreasing
        ) {
            return false;
        }
    }

    return true;
}
