#include <stdbool.h>
#include <stdlib.h>

static int compareFunction(const void *p1, const void *p2) {
    const int i1 = (*((const int*)p1));
    const int i2 = (*((const int*)p2));

    return ((i1 > i2) - (i1 < i2));
}

bool isGood(int* nums, int numsSize) {
    if (0 == numsSize) {
        return false;
    }

    /* Sort the given nums list in the ascending order. */
    qsort((void*)nums, numsSize, sizeof(*nums), &compareFunction);

    if (numsSize != ((nums[numsSize - 1]) + 1)) {
        /*
         * If the length of nums array does not equal to the largest value
         * in the nums array plus 1, nums array cannot be a good array.
         */
        return false;
    }

    for (int i = 1; i <= (nums[numsSize - 1]); ++i) {
        /*
         * Make sure 1 to nums[-1] all show in the nums array in the right
         * order.
         */
        if (i != (nums[i - 1])) {
            return false;
        }
    }

    return true;
}
