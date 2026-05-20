#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

static inline int min(const int e1, const int e2) {
    return ((e1 < e2) ? e1 : e2);
}

int jump(int* nums, int numsSize) {
    int answer = 0;

    /*
     * dp_state_array_ptr is the pointer of DP state array.
     *
     * dp_state_array_ptr[i] stores the minimum number jumps to reach index i
     * starting from index 0.
     *
     * dp_state_array_ptr[0] is always 0 since we start from index 0, do not
     * need any jump to reach index 0.
     * dp_state_array_ptr[i] is min(dp_state_array_ptr[j] + 1) if:
     * 1. i > j >= 0.
     * 2. Index j is reachable from index 0.
     * 2. j + (nums[j]) >= j.
     */
    int *dp_state_array_ptr = (
        (int*)malloc(sizeof(*dp_state_array_ptr) * numsSize)
    );

    dp_state_array_ptr[0] = 0;

    for (int i = 1; i < numsSize; ++i) {
        /*
         * dp_state_array_ptr[i] initial value is INT_MAX.
         * It means it is not reachable if we start from index 0.
         *
         * If index i is reachable if we start from index 0,
         * dp_state_array_ptr[i] will be a positive value.
         */
        dp_state_array_ptr[i] = INT_MAX;

        for (int j = 0; j < i; ++j) {
            if ((j + (nums[j])) < i) {
                /*
                 * If we cannot jump to index i from index j, skip it and
                 * continue to try next index j.
                 */
                continue;
            }

            dp_state_array_ptr[i] = min(
                dp_state_array_ptr[i],
                (dp_state_array_ptr[j]) + 1
            );
        }

        if (INT_MAX == (dp_state_array_ptr[i])) {
            /*
             * If current index i is not reachable if start from index 0, it is
             * impossible that we can last index when starting from index 0,
             * we can break loop right away.
             */
            answer = -1;

            goto FINAL_CLEANUP;
        }
    }

    answer = (dp_state_array_ptr[numsSize - 1]);

FINAL_CLEANUP:
    free(dp_state_array_ptr);
    dp_state_array_ptr = NULL;

    return answer;
}
