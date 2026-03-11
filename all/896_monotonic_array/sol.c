#include <stdbool.h>

typedef enum MONOTONIC_STYLE {
    NONE=0,
    INCREASING,
    DECREASING,
} MonotonicStyleEnum;

bool isMonotonic(int* nums, int numsSize) {
    MonotonicStyleEnum monotonic_style = NONE;

    for (int i = 1; i < numsSize; ++i) {
        if (NONE == monotonic_style) {
            if (nums[i] > nums[i - 1]) {
                monotonic_style = INCREASING;
            }
            else if (nums[i] < nums[i - 1]) {
                monotonic_style = DECREASING;
            }
        }
        else if (
            ((INCREASING == monotonic_style) && (nums[i] < nums[i - 1]))
            ||
            ((DECREASING == monotonic_style) && (nums[i] > nums[i - 1]))
        ) {
            return false;
        }
    }

    return true;
}
