#include <stddef.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *answer_array_ptr = (int*)malloc(sizeof(*answer_array_ptr) * numsSize);
    int previous_prefix_product = 1, previous_suffix_product = 1;

    if (NULL == answer_array_ptr) {
        (*returnSize) = 0;

        return NULL;
    }

    for (int i = 0; i < numsSize; ++i) {
        answer_array_ptr[i] = previous_prefix_product;
        previous_prefix_product *= nums[i];
    }

    for (int i = (numsSize - 1); i >= 0; --i) {
        answer_array_ptr[i] *= previous_suffix_product;
        previous_suffix_product *= nums[i];
    }

    (*returnSize) = numsSize;

    return answer_array_ptr;
}
