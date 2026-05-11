void sortColors(int* nums, int numsSize) {
    int colors_count_array[3] = {0};

    /*
     * Iterate the given nums array compute each color's count since we need to
     * use counting sort to sort the given nums array.
     */
    for (int i = 0; i < numsSize; ++i) {
        ++(colors_count_array[nums[i]]);
    }

    /* Iterate from 0 to numsSize - 1 to fill in all colors in order. */
    for (int i = 0, color_index = 0; i < numsSize; ++i) {
        while (0 == (colors_count_array[color_index])) {
            /* Find a color whose count is not 0. */
            ++color_index;
        }

        /* Fill in current color. */
        nums[i] = color_index;

        /* Decrease current color's count by 1. */
        --(colors_count_array[color_index]);
    }
}
