int findMin(int* nums, int numsSize) {
    int left_index = 0, right_index = (numsSize - 1);
    int middle_index = 0;

    while (left_index < right_index) {
        middle_index = (left_index + ((right_index - left_index) >> 1));

        if ((nums[middle_index]) < (nums[right_index])) {
            /*
             * The right part is sorted, the minimum element is in the left
             * part.
             */
            right_index = middle_index;
        }
        else {
            /*
             * Right part is not sorted and only left part is sorted,
             * the minimum element is in the right part.
             */
            left_index = (middle_index + 1);
        }
    }

    return (nums[left_index]);
}
