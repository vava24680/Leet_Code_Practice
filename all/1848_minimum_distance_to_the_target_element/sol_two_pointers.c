int getMinDistance(int* nums, int numsSize, int target, int start) {
    int left_index = start;
    int right_index = start;

    /*
     * Start from the start index and search towards to the left side and the
     * right side.
     */
    while ((left_index >= 0) || (right_index < numsSize)) {
        if (left_index >= 0) {
            if (target == (nums[left_index])) {
                return (start - left_index);
            }

            --left_index;
        }

        if (right_index < numsSize) {
            if (target == (nums[right_index])) {
                return (right_index - start);
            }

            ++right_index;
        }
    }

    return -1;
}
