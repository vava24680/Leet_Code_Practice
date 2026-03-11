#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

bool checkSubarraySum(int* nums, int numsSize, int k) {
    int *prefix_sum_array_ptr = (int*)malloc(
        sizeof(*prefix_sum_array_ptr) * (numsSize + 1)
    );
    bool answer = false;

    if (NULL == prefix_sum_array_ptr) {
        return false;
    }

    /*
     * prefix_sum_array_ptr[i + 1] is sum of nums[0], nums[1], ..., nums[i].
     * prefix_sum_array_ptr[0] = 0.
     */
    prefix_sum_array_ptr[0] = 0;

    /* Populate prefix sub array and check if there is any good subarray. */
    for (
        int subarray_end_index = 0;
        subarray_end_index < numsSize;
        ++subarray_end_index
    ) {
        prefix_sum_array_ptr[subarray_end_index + 1] = (
            prefix_sum_array_ptr[subarray_end_index]
            +
            nums[subarray_end_index]
        );

        if (
            (subarray_end_index > 0)
            &&
            (
                (0 != nums[subarray_end_index])
                ||
                (0 != nums[subarray_end_index - 1])
            )
            &&
            (prefix_sum_array_ptr[subarray_end_index + 1] < k)
        ) {
            continue;
        }

        for (
            int subarray_start_index = 0;
            subarray_start_index < subarray_end_index;
            ++subarray_start_index
        ) {
            if (
                0
                ==
                (
                    (
                        prefix_sum_array_ptr[subarray_end_index + 1]
                        -
                        prefix_sum_array_ptr[(subarray_start_index - 1) + 1]
                    )
                    %
                    k
                )
            ) {
                answer = true;

                goto FINAL_CLEANUP;
            }
        }
    }

FINAL_CLEANUP:
    free(prefix_sum_array_ptr);
    prefix_sum_array_ptr = NULL;

    return answer;
}
