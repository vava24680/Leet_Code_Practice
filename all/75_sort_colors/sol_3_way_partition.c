void swapTwoIntegers(int *int_1_ptr, int *int_2_ptr) {
    int tmp = (*int_1_ptr);
    (*int_1_ptr) = (*int_2_ptr);
    (*int_2_ptr) = tmp;
}

void sortColors(int* nums, int numsSize) {
    int next_0_index = 0;
    int next_2_index = (numsSize - 1);
    int current_index = 0;

    /* Use 3-way partition to sort an array that only has three values. */
    while (current_index <= next_2_index) {
        if (0 == (nums[current_index])) {
            swapTwoIntegers(&(nums[current_index]), &(nums[next_0_index]));

            ++next_0_index;
            ++current_index;
        }
        else if (2 == (nums[current_index])) {
            swapTwoIntegers(&(nums[current_index]), &(nums[next_2_index]));

            --next_2_index;
        }
        else {
            ++current_index;
        }
    }
}
