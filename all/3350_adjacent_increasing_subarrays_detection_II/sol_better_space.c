static inline int max(const int e1, const int e2) {
    return e1 > e2 ? e1 : e2;
}

static inline int min(const int e1, const int e2) {
    return e1 < e2 ? e1 : e2;
}

int maxIncreasingSubarrays(int* nums, int numsSize) {
    int answer = 0;
    int current_strictly_increasing_subarray_length = 1;
    int previous_strictly_increasing_subarray_length = 0;

    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] > nums[i - 1]) {
            ++current_strictly_increasing_subarray_length;
        }
        else {
            previous_strictly_increasing_subarray_length = \
                current_strictly_increasing_subarray_length;
            current_strictly_increasing_subarray_length = 1;
        }

        answer = max(
            answer,
            max(
                /* A whole strictly increasing subarray is cut in two half case. */
                current_strictly_increasing_subarray_length >> 1,
                /* Two adjacent but separated strictly increasing subarray case. */
                min(
                    previous_strictly_increasing_subarray_length,
                    current_strictly_increasing_subarray_length
                )
            )
        );
    }

    return answer;
}
