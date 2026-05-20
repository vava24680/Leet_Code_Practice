static inline int max(const int e1, const int e2) {
    return ((e1 > e2) ? e1 : e2);
}

int jump(int* nums, int numsSize) {
    int minimum_jumps_count = 0;

    /* This variable represents the farthest index that current jump can reach. */
    int current_jump_maximum_index = 0;

    /*
     * This variable represents the farthest index that can be reached from
     * the indices that we have traversed.
     *
     * This variable remains same functionality as in the LeetCode 55.
     */
    int farthest_index_can_be_reached = 0;

    for (int i = 0; i < (numsSize - 1); ++i) {
        if (i > farthest_index_can_be_reached) {
            return -1;
        }

        /*
         * Update the farthest index that can be reached from the indices
         * that we have traversed.
         */
        farthest_index_can_be_reached = max(
            farthest_index_can_be_reached,
            i + (nums[i])
        );

        if (i == current_jump_maximum_index) {
            if (farthest_index_can_be_reached <= current_jump_maximum_index) {
                /*
                 * If we need to a new jump but the farthest index that can be
                 * reached from the indices we have traversed is less than or
                 * equal to the farthest index that current jump can contribute,
                 * it means new jump cannot take us farther, so it's impossible
                 * to reach the target index.
                 *
                 * This check is optional.
                 */
                return -1;
            }

            /*
             * If current index is equal to the farthest index that current jump
             * can contribute, we must make another jump as next index is not
             * reachable by current jump.
             *
             * So we increase jump count by 1, we also update the farthest index
             * that this new jump can contribute as the farthest index that can
             * be reached from the indices we have traversed.
             */
            ++minimum_jumps_count;
            current_jump_maximum_index = farthest_index_can_be_reached;

            if (current_jump_maximum_index >= (numsSize - 1)) {
                /* If current jump maximum index is greater than or equal the
                 * last index, it means we can jump to last index by current
                 * jump, we do not need to iterate and return current minimum
                 * jumps count as answer.
                 */
                return minimum_jumps_count;
            }
        }
    }

    /*
     * Make sure the last index is covered within the range of the farthest index
     * can be reached from the indices that we have traversed.
     *
     * This check is optional.
     */
    if (farthest_index_can_be_reached < (numsSize - 1)) {
        return -1;
    }

    return minimum_jumps_count;
}
