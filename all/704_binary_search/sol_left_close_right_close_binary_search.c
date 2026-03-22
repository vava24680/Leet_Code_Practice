int search(int* nums, int numsSize, int target) {
    int left_index = 0, right_index = numsSize - 1;
    int middle_index = 0;

    while (left_index <= right_index) {
        middle_index = left_index + ((right_index - left_index) >> 1);

        if (nums[middle_index] == target) {
            return middle_index;
        }
        else if (target > nums[middle_index]) {
            left_index = middle_index + 1;
        }
        else {
            right_index = middle_index - 1;
        }
    }

    return -1;
}
