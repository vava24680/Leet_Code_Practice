#include <stddef.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} ValueIndexPairST;

static inline int min(const int i1, const int i2) {
    return ((i1 < i2) ? i1 : i2);
}

static inline int computeReversedValue(int x) {
    int reversed_x = 0;

    while (x > 0) {
        reversed_x = ((reversed_x * 10) + (x % 10));
        x /= 10;
    }

    return reversed_x;
}

static int valueIndexPairSTCompareFunction(const void *p1, const void *p2) {
    const ValueIndexPairST *value_index_pair_st_1_ptr = (
        (const ValueIndexPairST*)p1
    );
    const ValueIndexPairST *value_index_pair_st_2_ptr = (
        (const ValueIndexPairST*)p2
    );

    if (
        (value_index_pair_st_1_ptr->value)
        ==
        (value_index_pair_st_2_ptr->value)
    ) {
        return (
            (
                (value_index_pair_st_1_ptr->index)
                >
                (value_index_pair_st_2_ptr->index)
            )
            -
            (
                (value_index_pair_st_1_ptr->index)
                <
                (value_index_pair_st_2_ptr->index)
            )
        );
    }

    return (
        (
            (value_index_pair_st_1_ptr->value)
            >
            (value_index_pair_st_2_ptr->value)
        )
        -
        (
            (value_index_pair_st_1_ptr->value)
            <
            (value_index_pair_st_2_ptr->value)
        )
    );
}

static int findFirstEqualOrLargerThanElementIndexInValueIndexPairsSTArray(
    const int target_value,
    const int start_index,
    const int end_index,
    const ValueIndexPairST * const value_index_pairs_st_array_ptr
) {
    int left_index = start_index, right_index = end_index;
    int middle_index = 0;

    while (left_index < right_index) {
        middle_index = (left_index + ((right_index - left_index) >> 1));

        if (
            ((value_index_pairs_st_array_ptr[middle_index]).value)
            <
            target_value
        ) {
            left_index = (middle_index + 1);
        }
        else {
            right_index = middle_index;
        }
    }

    return left_index;
}

static int findFirstLargerThanElementIndexInValueIndexPairsSTArray(
    const int target_value,
    const int start_index,
    const int end_index,
    const ValueIndexPairST * const value_index_pairs_st_array_ptr
) {
    int left_index = start_index, right_index = end_index;
    int middle_index = 0;

    while (left_index < right_index) {
        middle_index = (left_index + ((right_index - left_index) >> 1));

        if (
            ((value_index_pairs_st_array_ptr[middle_index]).value)
            <=
            target_value
        ) {
            left_index = (middle_index + 1);
        }
        else {
            right_index = middle_index;
        }
    }

    return left_index;
}

static int findFirstLargerThanElementIndexInValueIndexPairsSTArrayByIndex(
    const int target_index,
    const int start_index,
    const int end_index,
    const ValueIndexPairST * const value_index_pairs_st_array_ptr
) {
    int left_index = start_index, right_index = end_index;
    int middle_index = 0;

    while (left_index < right_index) {
        middle_index = (left_index + ((right_index - left_index) >> 1));

        if (
            ((value_index_pairs_st_array_ptr[middle_index]).index)
            <=
            target_index
        ) {
            left_index = (middle_index + 1);
        }
        else {
            right_index = middle_index;
        }
    }

    return left_index;
}

int minMirrorPairDistance(int* nums, int numsSize) {
    int minimum_distance = numsSize;
    int reversed_number = 0;
    int reversed_number_first_index_in_valud_index_pairs_st_array = 0;
    int reversed_number_last_index_in_value_index_pairs_st_array = 0;
    int first_greater_than_index = 0;

    ValueIndexPairST *value_index_pairs_st_array_ptr = (
        (ValueIndexPairST*)malloc(
            sizeof(*value_index_pairs_st_array_ptr) * numsSize
        )
    );

    /* Set up the value index pairs array. */
    for (int i = 0; i < numsSize; ++i) {
        ((value_index_pairs_st_array_ptr[i]).value) = (nums[i]);
        ((value_index_pairs_st_array_ptr[i]).index) = i;
    }

    /* Sort the value index pairs array. */
    qsort(
        (void*)value_index_pairs_st_array_ptr,
        numsSize,
        sizeof(*value_index_pairs_st_array_ptr),
        &valueIndexPairSTCompareFunction
    );

    for (int i = 0; i < (numsSize - 1); ++i) {
        reversed_number = computeReversedValue(nums[i]);
        reversed_number_first_index_in_valud_index_pairs_st_array = (
            findFirstEqualOrLargerThanElementIndexInValueIndexPairsSTArray(
                reversed_number,
                0,
                numsSize,
                value_index_pairs_st_array_ptr
            )
        );

        if (
            (
                reversed_number_first_index_in_valud_index_pairs_st_array
                >=
                numsSize
            )
            ||
            (
                reversed_number
                !=
                (
                    (
                        value_index_pairs_st_array_ptr[
                            reversed_number_first_index_in_valud_index_pairs_st_array
                        ]
                    ).value
                )
            )
        ) {
            /*
             * If reversed number does not exist in the nums array,
             * current index i cannot pair with any j (i < j < numsSize)
             * to form a mirror pair, we can continue to next index i.
             */
            continue;
        }

        reversed_number_last_index_in_value_index_pairs_st_array = (
            findFirstLargerThanElementIndexInValueIndexPairsSTArray(
                reversed_number,
                0,
                numsSize,
                value_index_pairs_st_array_ptr
            )
            -
            1
        );

        if (
            reversed_number_last_index_in_value_index_pairs_st_array
            <
            reversed_number_first_index_in_valud_index_pairs_st_array
        ) {
            /* This case should not happen, but play safe. */
            continue;
        }

        /*
         * Find the first value index pair whose index is greater than i in
         * value index pairs array.
         *
         * If that valid index pair exists, the absolute distance of that
         * mirror pair will be the minimum among all the mirror pairs (i, j)
         * by using current index as i.
         */
        first_greater_than_index = (
            findFirstLargerThanElementIndexInValueIndexPairsSTArrayByIndex(
                i,
                reversed_number_first_index_in_valud_index_pairs_st_array,
                reversed_number_last_index_in_value_index_pairs_st_array + 1,
                value_index_pairs_st_array_ptr
            )
        );

        if (
            first_greater_than_index
            >
            reversed_number_last_index_in_value_index_pairs_st_array
        ) {
            /* Do not find a valid value inex pair. */
            continue;
        }

        /*
         * Compute the minimum distance among all the mirror pairs can generated
         * currently, and update global recorded minimum distance if needed.
         */
        minimum_distance = min(
            minimum_distance,
            (value_index_pairs_st_array_ptr[first_greater_than_index].index) - i
        );
    }

    free(value_index_pairs_st_array_ptr);
    value_index_pairs_st_array_ptr = NULL;

    if (numsSize == minimum_distance) {
        return -1;
    }

    return minimum_distance;
}
