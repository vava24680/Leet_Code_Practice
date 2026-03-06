#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *answer_array_ptr = (int*)malloc(sizeof(*answer_array_ptr) * 2);

    for (int i = 0; i < numsSize; ++i) {
        for (int j = (i + 1); j < numsSize; ++j) {
            if ((nums[i] + nums[j]) == target) {
                *returnSize = 2;

                answer_array_ptr[0] = i;
                answer_array_ptr[1] = j;

                return answer_array_ptr;
            }
        }
    }

    (*returnSize) = 0;

    return answer_array_ptr;
}
