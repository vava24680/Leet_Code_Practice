int findDuplicate(int* nums, int numsSize) {
    /*
     * Use binary search to find the duplicate value.
     * Check notes for details.
     */
    int left_value = 0, right_value = numsSize - 1;
    int middle_value = 0;
    int count = 0;

    while (left_value < right_value) {
        middle_value = (left_value + ((right_value - left_value) >> 1));
        count = 0;

        /*
         * Count how many numbers in the nums array are less than or equal to
         * the middle value.
         */
        for (int i = 0; i < numsSize; ++i) {
            if (nums[i] <= middle_value) {
                ++count;
            }
        }

        if (count <= middle_value) {
            left_value = middle_value + 1;
        }
        else {
            right_value = middle_value;
        }
    }

    return left_value;
}
