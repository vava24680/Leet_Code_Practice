#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct {
    int *array_ptr;
    int array_length;
    int next_available_index;
} DynamicIntArrayST;

static int compareFunction(const void *p1, const void *p2) {
    const int i1 = (*((const int*)p1));
    const int i2 = (*((const int*)p2));

    return ((i1 > i2) - (i1 < i2));
}

static bool addNewValueToDynamicIntArrayST(
    const int x,
    DynamicIntArrayST * dynamic_int_array_st_ptr
) {
    int *new_array_ptr = NULL;
    int new_array_length = 0;

    if (
        (dynamic_int_array_st_ptr->next_available_index)
        >=
        (dynamic_int_array_st_ptr->array_length)
    ) {
        if (0 == (dynamic_int_array_st_ptr->array_length)) {
            new_array_length = 4;
        }
        else {
            new_array_length = ((dynamic_int_array_st_ptr->array_length) << 1);
        }

        new_array_ptr = (
            (int*)realloc(
                dynamic_int_array_st_ptr->array_ptr,
                (
                    sizeof(*(dynamic_int_array_st_ptr->array_ptr))
                    *
                    new_array_length
                )
            )
        );

        if (NULL == new_array_ptr) {
            return false;
        }

        (dynamic_int_array_st_ptr->array_length) = new_array_length;
        (dynamic_int_array_st_ptr->array_ptr) = new_array_ptr;
    }

    (dynamic_int_array_st_ptr->array_ptr)[
        (dynamic_int_array_st_ptr->next_available_index)++
    ] = x;

    return true;
}

static int findFirstEqualOrLargerThanIndex(
    const int *array_ptr,
    const int start_index,
    const int end_index,
    const int target_value
) {
    int left_index = start_index;
    int right_index = end_index;
    int middle_index = 0;

    while (left_index < right_index) {
        middle_index = (left_index + ((right_index - left_index) >> 1));

        if ((array_ptr[middle_index]) < target_value) {
            left_index = (middle_index + 1);
        }
        else {
            right_index = middle_index;
        }
    }

    return left_index;
}

static void getDifferenceBetweenTwoIntArraysValues(
    const int * int_array_1_ptr,
    const int * int_array_2_ptr,
    const int int_array_1_length,
    const int int_array_2_length,
    DynamicIntArrayST * dynamic_int_array_st_ptr
) {
    /*
     * Assume int array 1 and int array 2 are both sorted in the ascending
     * order.
     *
     * We use binary search to find all unique values that are the int array 1
     * but not in the int array 2.
     */
    int first_greater_than_or_equal_index = 0;

    for (int i = 0; i < int_array_1_length; ++i) {
        if (i && ((int_array_1_ptr[i - 1]) == (int_array_1_ptr[i]))) {
            /* Skip repeated values. */
            continue;
        }

        /*
         * Use binary search to find the first whose element is equal to
         * or greater than int_array_1_ptr[i].
         */
        first_greater_than_or_equal_index = findFirstEqualOrLargerThanIndex(
            int_array_2_ptr,
            0,
            int_array_2_length,
            int_array_1_ptr[i]
        );

        if (
            (first_greater_than_or_equal_index < int_array_2_length)
            &&
            (
                (int_array_2_ptr[first_greater_than_or_equal_index])
                ==
                (int_array_1_ptr[i])
            )
        ) {
            /*
             * If int_array_1_ptr[i] shows in int array 2, continue to try next
             * int_array_1_ptr[i].
             */
            continue;
        }

        /*
         * Current iterated int_array_1_ptr[i] does not in int array 2, add it
         * to answer list.
         */
        addNewValueToDynamicIntArrayST(
            int_array_1_ptr[i],
            dynamic_int_array_st_ptr
        );
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findDifference(
    int* nums1,
    int nums1Size,
    int* nums2,
    int nums2Size,
    int* returnSize,
    int** returnColumnSizes
) {
    int **answer_array_ptr = (int**)malloc(sizeof(*answer_array_ptr) * 2);
    (*returnColumnSizes) = (int*)malloc(sizeof(**returnColumnSizes) * 2);

    DynamicIntArrayST nums1_answer_array_st = {
        .array_ptr = NULL,
        .array_length = 0,
        .next_available_index = 0,
    };
    DynamicIntArrayST nums2_answer_array_st = {
        .array_ptr = NULL,
        .array_length = 0,
        .next_available_index = 0,
    };

    /* Sort the nums1 array in the ascending order. */
    qsort(nums1, nums1Size, sizeof(*nums1), &compareFunction);

    /* Sort the nums2 array in the ascending order. */
    qsort(nums2, nums2Size, sizeof(*nums2), &compareFunction);

    /*
     * Get all the unique values that are in nums1 array but no in the nums2
     * array.
     */
    getDifferenceBetweenTwoIntArraysValues(
        nums1,
        nums2,
        nums1Size,
        nums2Size,
        &nums1_answer_array_st
    );

    /*
     * Get all the unique values that are in nums2 array but no in the nums1
     * array.
     */
    getDifferenceBetweenTwoIntArraysValues(
        nums2,
        nums1,
        nums2Size,
        nums1Size,
        &nums2_answer_array_st
    );

    answer_array_ptr[0] = (nums1_answer_array_st.array_ptr);
    (*returnColumnSizes)[0] = (nums1_answer_array_st.next_available_index);

    answer_array_ptr[1] = (nums2_answer_array_st.array_ptr);
    (*returnColumnSizes)[1] = (nums2_answer_array_st.next_available_index);

    (*returnSize) = 2;

    return answer_array_ptr;
}
