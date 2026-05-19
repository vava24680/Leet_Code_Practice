#include <stdbool.h>

static inline int max(const int e1, const int e2) {
    return ((e1 > e2) ? e1 : e2);
}

bool canJump(int* nums, int numsSize) {
    /*
     * Use this variable to record the furthest index can be reached from
     * the indices that we have traversed.
     */
    int furthest_index_can_be_reached = (nums[0]);

    for (int i = 1; i < numsSize; ++i) {
        if (i > furthest_index_can_be_reached) {
            /*
             * If current index is larger than the furthest index that can be
             * reached from all the previous indices that we have traversed,
             * it is impossible that we can reach current index and further
             * indices, so return false immediately.
             */
            return false;
        }

        /*
         * Update furthest index that can be reached from all the indices
         * that we have traversed.
         */
        furthest_index_can_be_reached = max(
            furthest_index_can_be_reached,
            i + (nums[i])
        );
    }

    return true;
}
