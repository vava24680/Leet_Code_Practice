#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

bool canJump(int* nums, int numsSize) {
    /*
     * dp_state_array_ptr is the pointer of DP state array.
     *
     * dp_state_array_ptr[i] represents if we can jump to index i from index 0.
     *
     * dp_state_array_ptr[0] is always true.
     * dp_state_array_ptr[i] is true if there is index j who is smaller than i
     * and dp_state_array_ptr[j] is true and we can jump to index i
     * from index j, which means (j + (nums[j])) >= i.
     */
    bool *dp_state_array_ptr = (
        (bool*)malloc(sizeof(*dp_state_array_ptr) * numsSize)
    );
    bool answer = false;

    dp_state_array_ptr[0] = true;

    for (int i = 1; i < numsSize; ++i) {
        dp_state_array_ptr[i] = false;

        for (int j = 0; j < i; ++j) {
            if ((dp_state_array_ptr[j]) && ((j + (nums[j])) >= i)) {
                dp_state_array_ptr[i] = true;

                break;
            }
        }
    }

    answer = (dp_state_array_ptr[numsSize - 1]);

    free(dp_state_array_ptr);
    dp_state_array_ptr = NULL;

    return answer;
}
