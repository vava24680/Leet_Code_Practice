#include <stdbool.h>

bool isStrictlyIncreasingSubarray(
    const int * const array_ptr,
    const int length
) {
    for (int i = 1; i < length; ++i) {
        if (array_ptr[i] <= array_ptr[i - 1]) {
            return false;
        }
    }

    return true;
}

bool hasIncreasingSubarrays(int* nums, int numsSize, int k) {
    for (int i = 0; i <= (numsSize - (2 * k)); ++i) {
        /*
         * Use fixed size sliding window to get a subarray whose length is 2k,
         * and check if the first half and the last half of that subarray are
         * both strictly increasing.
         */
        if (
            isStrictlyIncreasingSubarray(nums + i, k)
            &&
            isStrictlyIncreasingSubarray(nums + i + k, k)
        ) {
            return true;
        }
    }

    return false;
}
