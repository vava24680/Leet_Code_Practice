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

static void getDifferenceBetweenTwoIntArraysValues(
    const int * const int_array_1_ptr,
    const int * const int_array_2_ptr,
    const int int_array_1_length,
    const int int_array_2_length,
    DynamicIntArrayST * dynamic_int_array_st_ptr
) {
    /*
     * Assume int array 1 and int array 2 are both sorted in the ascending
     * order.
     *
     * We use two pointers to find all unique values that are the int array 1
     * but not in the int array 2.
     */
    int i = 0, j = 0;

    while ((i < int_array_1_length) && (j < int_array_2_length)) {
        if ((int_array_1_ptr[i]) == (int_array_2_ptr[j])) {
            /*
             * As int_array_1_ptr[i] is equal to int_array_2_ptr[j], it cannot
             * be the value we want, just increase the index i by 1.
             * The index j is not increased since there might be more values
             * tha are as same as int_array_2_ptr[j] in the rest of values in
             * the int array 1.
             */
            ++i;
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
             */
            if (
                (0 == (dynamic_int_array_st_ptr->next_available_index))
                ||
                (
                    (
                        (dynamic_int_array_st_ptr->array_ptr)[
                            (dynamic_int_array_st_ptr->next_available_index) - 1
                        ]
                    )
                    !=
                    (int_array_1_ptr[i])
                )
            ) {
                /*
                 * Only add int_array_1_ptr[i] to answer array if:
                 * 1. Answer array is empty.
                 * 2. int_array_1_ptr[i] is different than the previous
                 *    value added to answer array.
                 */
                addNewValueToDynamicIntArrayST(
                    int_array_1_ptr[i],
                    dynamic_int_array_st_ptr
                );
            }

            ++i;
        }
    }

    while (i < int_array_1_length) {
        /*
         * If we still not reach the end of int arrary 1, the rest of unique
         * values also shows in int array 1, we need to add them to answer array
         * too.
         */
        if (
            (0 == (dynamic_int_array_st_ptr->next_available_index))
            ||
            (
                (
                    (dynamic_int_array_st_ptr->array_ptr)[
                        (dynamic_int_array_st_ptr->next_available_index) - 1
                    ]
                )
                !=
                (int_array_1_ptr[i])
            )
        ) {
            /*
             * Only add int_array_1_ptr[i] to answer array if:
             * 1. Answer array is empty.
             * 2. int_array_1_ptr[i] is different than the previous
             *    value added to answer array.
             */
            addNewValueToDynamicIntArrayST(
                int_array_1_ptr[i],
                dynamic_int_array_st_ptr
            );
        }

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
