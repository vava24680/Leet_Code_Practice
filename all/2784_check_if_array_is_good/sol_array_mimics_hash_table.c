#include <limits.h>
#include <stdbool.h>

#define MAXIMUM_VALUE (200)

static inline int max(const int i1, const int i2) {
    return ((i1 > i2) ? i1 : i2);
}

bool isGood(int* nums, int numsSize) {
    if (0 == numsSize) {
        return false;
    }

    int values_counter_array[MAXIMUM_VALUE + 1] = {0};
    int maximum_value = INT_MIN;

    for (int i = 0; i < numsSize; ++i) {
        ++(values_counter_array[nums[i]]);
        maximum_value = max(maximum_value, nums[i]);
    }

    if (numsSize != (maximum_value + 1)) {
        /*
         * If the length of nums array does not equal to the largest value
         * in the nums array plus 1, nums array cannot be a good array.
         */
        return false;
    }

    for (int i = 1; i < maximum_value; ++i) {
        /*
         * Make sure every value from 1 to (maximum value - 1) all show only
         * once in the nums array.
         */
        if (1 != (values_counter_array[i])) {
            return false;
        }
    }

    /* Make sure the maximum value shows twice in the nums array. */
    return (2 == values_counter_array[maximum_value]);
}
