#include <stdbool.h>
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
    int maximum_subarray_length = 0;
    int left_subarray_length = 1, right_subarray_length = 1;
    int middle_subarray_length = 0;
    bool current_subarray_is_valid = false;

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

    /*
     * Use binary search to find the first not valid subarray length in all the
     * possible subarray lengths.
     */
    left_subarray_length = 1;
    right_subarray_length = ((numsSize >> 1) + 1);

    while (left_subarray_length < right_subarray_length) {
        middle_subarray_length = (
            left_subarray_length
            +
            ((right_subarray_length - left_subarray_length) >> 1)
        );

        current_subarray_is_valid = false;

        for (
            int i = (middle_subarray_length - 1);
            i < ((numsSize - middle_subarray_length - 1) + 1);
            ++i
        ) {
            if (
                (
                    maximum_subarrays_length_left_array_ptr[i]
                    >=
                    middle_subarray_length
                )
                &&
                (
                    maximum_subarrays_length_right_array_ptr[i + 1]
                    >=
                    middle_subarray_length
                )
            ) {
                current_subarray_is_valid = true;

                break;
            }
        }

        if (current_subarray_is_valid) {
            left_subarray_length = middle_subarray_length + 1;
        }
        else {
            right_subarray_length = middle_subarray_length;
        }
    }

    /*
     * Because the subarray we find is the first that is not valid, we need to
     * subtract 1 from it to get the maximum one that is valid.
     */
    maximum_subarray_length = left_subarray_length - 1;

    free(array_ptr);
    array_ptr = NULL;

    return maximum_subarray_length;
}
