#include <limits.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int value;
    int index;
} ValueIndexPairST;

static int min(const int i1, const int i2) {
    return ((i1 < i2) ? i1 : i2);
}

static int compareFunction(const void *p1, const void *p2) {
    const ValueIndexPairST *value_index_pair_1_ptr = (
        (const ValueIndexPairST*)p1
    );
    const ValueIndexPairST *value_index_pair_2_ptr = (
        (const ValueIndexPairST*)p2
    );

    if ((value_index_pair_1_ptr->value) == (value_index_pair_2_ptr->value)) {
        return (
            ((value_index_pair_1_ptr->index) > (value_index_pair_2_ptr->index))
            -
            ((value_index_pair_1_ptr->index) < (value_index_pair_2_ptr->index))
        );
    }

    return (
        ((value_index_pair_1_ptr->value) > (value_index_pair_2_ptr->value))
        -
        ((value_index_pair_1_ptr->value) < (value_index_pair_2_ptr->value))
    );
}

int minimumDistance(int* nums, int numsSize) {
    ValueIndexPairST *value_index_pairs_st_array_ptr = (
        (ValueIndexPairST*)malloc(sizeof(*value_index_pairs_st_array_ptr) * numsSize)
    );
    int minimum_distance = INT_MAX;
    int first_index = 0;

    for (int i = 0; i < numsSize; ++i) {
        /* Pack index and its corresponding element value into a pair. */
        (value_index_pairs_st_array_ptr[i].value) = (nums[i]);
        (value_index_pairs_st_array_ptr[i].index) = i;
    }

    /* Sort all pairs by value and index in the ascending order. */
    qsort(
        (void*)value_index_pairs_st_array_ptr,
        numsSize,
        sizeof(*value_index_pairs_st_array_ptr),
        &compareFunction
    );

    while (first_index < (numsSize - 3 + 1)) {
        if (
            ((value_index_pairs_st_array_ptr[first_index + 1]).value)
            !=
            ((value_index_pairs_st_array_ptr[first_index]).value)
        ) {
            /*
             * Value in the current pair is not equal to the value in the
             * next pair, continue to next pair to try to find a good tuple.
             */
            first_index = (first_index + 1);

            continue;
        }
        else if (
            ((value_index_pairs_st_array_ptr[first_index + 2]).value)
            !=
            ((value_index_pairs_st_array_ptr[first_index]).value)
        ) {
            /*
             * Value in the current pair is not equal to the value in the
             * pair after the next pair, continue to the pair after the next
             * pair to try to find a good tuple.
             */
            first_index = (first_index + 2);

            continue;
        }

        /* Find a possible good tuple that might have minimum distance. */
        minimum_distance = min(
            minimum_distance,
            (
                ((value_index_pairs_st_array_ptr[first_index + 2]).index)
                -
                ((value_index_pairs_st_array_ptr[first_index + 1]).index)
            )
            +
            (
                ((value_index_pairs_st_array_ptr[first_index + 1]).index)
                -
                ((value_index_pairs_st_array_ptr[first_index]).index)
            )
            +
            (
                ((value_index_pairs_st_array_ptr[first_index + 2]).index)
                -
                ((value_index_pairs_st_array_ptr[first_index]).index)
            )
        );

        /* Move to next pair to try to find a good tuple. */
        first_index += 1;
    }

    free(value_index_pairs_st_array_ptr);
    value_index_pairs_st_array_ptr = NULL;

    if (INT_MAX == minimum_distance) {
        return -1;
    }

    return minimum_distance;
}
