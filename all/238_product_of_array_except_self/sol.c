#include <stddef.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *array_ptr = (int*)malloc(sizeof(*array_ptr) * ((numsSize + 1) * 2));
    int *answer_array_ptr = (int*)malloc(sizeof(*answer_array_ptr) * numsSize);

    /*
     * prefix_product_array_ptr[i + 1] stores the product of
     * nums[0] * nums[1] * ... * nums[i].
     *
     * prefix_product_array_ptr[0] = 1.
     */
    int *prefix_product_array_ptr = array_ptr;

    /*
     * suffix_product_array_ptr[i] stores the product of
     * nums[i] * nums[i + 1] * ... * nums[numsSize - 1].
     *
     * suffix_product_array_ptr[numsSize] = 1.
     */
    int *suffix_product_array_ptr = (array_ptr + (numsSize + 1));

    prefix_product_array_ptr[0] = 1;
    suffix_product_array_ptr[numsSize] = 1;

    for (int i = 0, j = (numsSize - 1); (i < numsSize) && (j >= 0); ++i, --j) {
        prefix_product_array_ptr[i + 1] = (
            prefix_product_array_ptr[i] * nums[i]
        );
        suffix_product_array_ptr[j] = (
            suffix_product_array_ptr[j + 1] * nums[j]
        );
    }

    for (int i = 0; i < numsSize; ++i) {
        answer_array_ptr[i] = (
            prefix_product_array_ptr[i] * suffix_product_array_ptr[i + 1]
        );
    }

    free(array_ptr);
    array_ptr = NULL;

    (*returnSize) = numsSize;

    return answer_array_ptr;
}
