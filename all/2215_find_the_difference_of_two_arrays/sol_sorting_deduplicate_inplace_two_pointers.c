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

static int deduplicateSortedIntArray(
    int * const array_ptr,
    const int array_length
) {
    if (0 == array_length) {
        return 0;
    }

    int next_unique_element_index = 1;

    for (int i = 1; i < array_length; ++i) {
        if ((array_ptr[i - 1]) == (array_ptr[i])) {
            continue;
        }

        array_ptr[next_unique_element_index] = (array_ptr[i]);
        ++next_unique_element_index;
    }

    return next_unique_element_index;
}

static void getDifferenceBetweenTwoIntArraysValues(
    const int * const int_array_1_ptr,
    const int * const int_array_2_ptr,
    const int int_array_1_length,
    const int int_array_2_length,
    DynamicIntArrayST * dynamic_int_array_st_ptr
) {
    /*
     * Assume int array 1 and int array 2 are both sorted in the ascending
     * order and only have unique values.
     *
     * We use two pointers to find all unique values that are the int array 1
     * but not in the int array 2.
     */
    int i = 0, j = 0;

    while ((i < int_array_1_length) && (j < int_array_2_length)) {
        if ((int_array_1_ptr[i]) == (int_array_2_ptr[j])) {
            /*
             * As int_array_1_ptr[i] is equal to int_array_2_ptr[j], it cannot
             * be the value we want, just increase the index i and the index j
             * by 1.
             * The index j is also increased since all values in the int array 1
             * and the int array 2 are unique. There won't be other elements
             * whose value is int_array_1_ptr[i] in the rest of int array 1.
             */
            ++i;
            ++j;
        }
        else if ((int_array_1_ptr[i]) > (int_array_2_ptr[j])) {
            /*
             * As int_array_1_ptr[i] is greater than int_array_2_ptr[j],
             * we do not know whether int_array_1_ptr[i] only shows in the
             * int array 1, we need to increase the index j by 1 to check
             * more values.
             */
            ++j;
        }
        else {
            /*
             * As int_array_1_ptr[i] is less than int_array_2_ptr[j], and since
             * int array 2 is sorted, we cannot find int_array_1_ptr[i] in
             * the int_array_2_ptr[j:], so int_array_1_ptr[i] must only show in
             * the int array 1.
             * Also, all values in the given int array 1 are unique, we can add
             * int_array_1_ptr[i] to answer array.
             */
            addNewValueToDynamicIntArrayST(
                int_array_1_ptr[i],
                dynamic_int_array_st_ptr
            );

            ++i;
        }
    }

    while (i < int_array_1_length) {
        /*
         * If we still not reach the end of int arrary 1, the rest of values in
         * the int array 1 must also shows in int array 1 only, we need to add
         * them to answer array too.
         */
        addNewValueToDynamicIntArrayST(
            int_array_1_ptr[i],
            dynamic_int_array_st_ptr
        );

        ++i;
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

    int nums1_array_length_after_deduplicate = 0;
    int nums2_array_length_after_deduplicate = 0;
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

    nums1_array_length_after_deduplicate = deduplicateSortedIntArray(
        nums1,
        nums1Size
    );
    nums2_array_length_after_deduplicate = deduplicateSortedIntArray(
        nums2,
        nums2Size
    );

    /*
     * Get all the unique values that are in nums1 array but no in the nums2
     * array.
     */
    getDifferenceBetweenTwoIntArraysValues(
        nums1,
        nums2,
        nums1_array_length_after_deduplicate,
        nums2_array_length_after_deduplicate,
        &nums1_answer_array_st
    );

    /*
     * Get all the unique values that are in nums2 array but no in the nums1
     * array.
     */
    getDifferenceBetweenTwoIntArraysValues(
        nums2,
        nums1,
        nums2_array_length_after_deduplicate,
        nums1_array_length_after_deduplicate,
        &nums2_answer_array_st
    );

    answer_array_ptr[0] = (nums1_answer_array_st.array_ptr);
    (*returnColumnSizes)[0] = (nums1_answer_array_st.next_available_index);

    answer_array_ptr[1] = (nums2_answer_array_st.array_ptr);
    (*returnColumnSizes)[1] = (nums2_answer_array_st.next_available_index);

    (*returnSize) = 2;

    return answer_array_ptr;
}
