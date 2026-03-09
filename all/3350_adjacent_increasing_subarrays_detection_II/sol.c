#include <stdlib.h>

static inline int max(const int e1, const int e2) {
    return e1 > e2 ? e1 : e2;
}

static inline int min(const int e1, const int e2) {
    return e1 < e2 ? e1 : e2;
}

int maxIncreasingSubarrays(int* nums, int numsSize) {
    int *array_ptr = (int*)malloc(sizeof(int) * 2 * numsSize);
    int *maximum_subarrays_length_left_array_ptr = array_ptr;
    int *maximum_subarrays_length_right_array_ptr = array_ptr + numsSize;
    int maximum_k = 0;

    /*
     * maximum_subarrays_length_left_array_ptr[i] stores the maximum length of
     * the increasing subarray that ends at nums[i].
     */
    maximum_subarrays_length_left_array_ptr[0] = 1;

    /*
     * maximum_subarrays_length_right_array_ptr[i] stores the maximum length of
     * the increasing subarray that starts at nums[i].
     */
    maximum_subarrays_length_right_array_ptr[numsSize - 1] = 1;

    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] > nums[i - 1]) {
            maximum_subarrays_length_left_array_ptr[i] = (
                maximum_subarrays_length_left_array_ptr[i - 1] + 1
            );
        }
        else {
            maximum_subarrays_length_left_array_ptr[i] = 1;
        }

        if (nums[numsSize - 1 - i] < nums[numsSize - i]) {
            maximum_subarrays_length_right_array_ptr[numsSize - 1 - i] = (
                maximum_subarrays_length_right_array_ptr[numsSize - i] + 1
            );
        }
        else {
            maximum_subarrays_length_right_array_ptr[numsSize - 1 - i] = 1;
        }
    }

    for (int i = 0; i < (numsSize - 1); ++i) {
        maximum_k = max(
            maximum_k,
            min(
                maximum_subarrays_length_left_array_ptr[i],
                maximum_subarrays_length_right_array_ptr[i + 1]
            )
        );
    }

    free(array_ptr);

    return maximum_k;
}
