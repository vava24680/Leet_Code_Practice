#include <stddef.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} ValueAndIndexPairST;

int valueAndIndexPairSTCompareFunction(const void *p1, const void *p2) {
    const ValueAndIndexPairST *vip_1_ptr = ((const ValueAndIndexPairST*)p1);
    const ValueAndIndexPairST *vip_2_ptr = ((const ValueAndIndexPairST*)p2);

    if ((vip_1_ptr->value) == (vip_2_ptr->value)) {
        return (
            ((vip_1_ptr->index) > (vip_2_ptr->index))
            -
            ((vip_1_ptr->index) < (vip_2_ptr->index))
        );
    }

    return (
        ((vip_1_ptr->value) > (vip_2_ptr->value))
        -
        ((vip_1_ptr->value) < (vip_2_ptr->value))
    );
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* distance(int* nums, int numsSize, int* returnSize) {
    long long *answer_array_ptr = (
        (long long*)calloc(numsSize, sizeof(*answer_array_ptr))
    );
    ValueAndIndexPairST *value_and_index_pairs_st_array_ptr = (
        (ValueAndIndexPairST*)malloc(
            sizeof(*value_and_index_pairs_st_array_ptr) * numsSize
        )
    );
    long long total_distance_from_head = 0LL;
    long long total_distance_from_tail = 0LL;
    long long distance_between_current_index_and_previous_index = 0LL;
    long long distance_between_current_index_and_next_index = 0LL;
    int current_has_same_value_indices_count = 1;

    /* Set up value and index pairs array. */
    for (int i = 0; i < numsSize; ++i) {
        (value_and_index_pairs_st_array_ptr[i]).value = (nums[i]);
        (value_and_index_pairs_st_array_ptr[i]).index = i;
    }

    /* Sort value and index pairs array. */
    qsort(
        (void*)value_and_index_pairs_st_array_ptr,
        numsSize,
        sizeof(*value_and_index_pairs_st_array_ptr),
        &valueAndIndexPairSTCompareFunction
    );

    for (int i = 1; i < numsSize; ++i) {
        /*
         * For each index in a indices list, we leverage prefix sum and
         * suffix sum to compute total distance for that index.
         *
         * Please check notes for detailed explanation.
         */
        if (
            ((value_and_index_pairs_st_array_ptr[i]).value)
            !=
            ((value_and_index_pairs_st_array_ptr[i - 1]).value)
        ) {
            /*
             * The element value of current iterated index is different from
             * the element value of previous iterated index, which means this
             * is the start of a new indices list.
             *
             * Reset total distance from head to 0 and same value indices
             * counter to 1.
             */
            total_distance_from_head = 0LL;
            current_has_same_value_indices_count = 1;
        }
        else {
            /*
             * Leverage prefix sum to compute total distance between current
             * index and all indices before it.
             */
            distance_between_current_index_and_previous_index = (
                (long long)(
                    ((value_and_index_pairs_st_array_ptr[i]).index)
                    -
                    ((value_and_index_pairs_st_array_ptr[i - 1]).index)
                )
            );

            total_distance_from_head += (
                distance_between_current_index_and_previous_index
                *
                current_has_same_value_indices_count
            );

            ++current_has_same_value_indices_count;
        }

        /*
         * Accumulate current computed total distance from head to the
         * corresponding slot in the answer array for the current iterated
         * index.
         */
        answer_array_ptr[(value_and_index_pairs_st_array_ptr[i]).index] += (
            total_distance_from_head
        );
    }

    /*
     * Reset current has same value indices counter to 1 before iterating
     * backward and leveraging suffix sum to compute total distance from tail.
     */
    current_has_same_value_indices_count = 1;

    for (int i = (numsSize - 2); i >= 0; --i) {
        if (
            ((value_and_index_pairs_st_array_ptr[i]).value)
            !=
            ((value_and_index_pairs_st_array_ptr[i + 1]).value)
        ) {
            /*
             * The element value of current iterated index is different from
             * the element value of previous iterated index, which means this
             * is the start of a new indices list.
             *
             * Reset total distance from tail to 0 and same value indices
             * counter to 1.
             */
            total_distance_from_tail = 0LL;
            current_has_same_value_indices_count = 1;
        }
        else {
            /*
             * Leverage suffix sum to compute total distance between current
             * index and all indices after it.
             */
            distance_between_current_index_and_next_index = (
                (long long)(
                    ((value_and_index_pairs_st_array_ptr[i + 1]).index)
                    -
                    ((value_and_index_pairs_st_array_ptr[i]).index)
                )
            );

            total_distance_from_tail += (
                distance_between_current_index_and_next_index
                *
                current_has_same_value_indices_count
            );

            ++current_has_same_value_indices_count;
        }

        /*
         * Accumulate current computed total distance from tail to the
         * corresponding slot in the answer array for the current iterated
         * index.
         */
        answer_array_ptr[(value_and_index_pairs_st_array_ptr[i]).index] += (
            total_distance_from_tail
        );
    }

    free(value_and_index_pairs_st_array_ptr);
    value_and_index_pairs_st_array_ptr = NULL;

    (*returnSize) = numsSize;

    return answer_array_ptr;
}
