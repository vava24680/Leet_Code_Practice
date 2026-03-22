int search(int* nums, int numsSize, int target) {
    /*
     * Use find the first equal or greater than pattern to implement.
     *
     * Since all elements in nums are unique, if the middle element
     * is the target, return middle index directly.
     */
    int left_index = 0, right_index = numsSize;
    int middle_index = 0;

    while (left_index < right_index) {
        middle_index = (left_index + ((right_index - left_index) >> 1));

        if (target == (nums[middle_index])) {
            return middle_index;
        }
        else if (nums[middle_index] < target) {
            left_index = middle_index + 1;
        }
        else {
            right_index = middle_index;
        }
    }

    return -1;
}
