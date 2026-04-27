#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct AnswerArrayStruct {
    int *array_ptr;
    int array_length;
    int next_available_idx;
} AnswerArrayST;

int compareFunction(const void *p1, const void *p2) {
    const int i1 = (*((const int*)p1));
    const int i2 = (*((const int*)p2));

    return ((i1 > i2) - (i1 < i2));
}

bool addElementToAnswerArrayST(
    AnswerArrayST * const answer_array_st,
    const int x
) {
    int *tmp_array_ptr = NULL;
    int new_array_length = 0;

    if (
        (answer_array_st->next_available_idx)
        >=
        (answer_array_st->array_length)
    ) {
        if (0 == (answer_array_st->array_length)) {
            new_array_length = 4;
        }
        else {
            new_array_length = ((answer_array_st->array_length) << 1);
        }

        tmp_array_ptr = (
            (int*)realloc(
                answer_array_st->array_ptr,
                sizeof(*(answer_array_st->array_ptr)) * new_array_length
            )
        );

        if (NULL == tmp_array_ptr) {
            return false;
        }

        answer_array_st->array_length = new_array_length;
        answer_array_st->array_ptr = tmp_array_ptr;
    }

    (answer_array_st->array_ptr)[(answer_array_st->next_available_idx)++] = x;

    return true;
}

int* intersection(
    int* nums1,
    int nums1Size,
    int* nums2,
    int nums2Size,
    int* returnSize
) {
    AnswerArrayST answer_array_st = {
        .array_ptr = NULL,
        .array_length = 0,
        .next_available_idx = 0,
    };
    int previous_same_element = 0;

    /* Sort the nums1 array in the ascending order. */
    qsort((void*)nums1, (size_t)nums1Size, sizeof(int), &compareFunction);

    /* Sort the nums2 array in the ascending order. */
    qsort((void*)nums2, (size_t)nums2Size, sizeof(int), &compareFunction);

    for (
        int idx_1 = 0, idx_2 = 0;
        (idx_1 < nums1Size) && (idx_2 < nums2Size);
    ) {
        if (nums1[idx_1] == nums2[idx_2]) {
            /*
             * If current iterated two values are the same, we might find a new
             * intersected value.
             */
            if (
                (0 == answer_array_st.next_available_idx)
                ||
                (previous_same_element != nums1[idx_1])
            ) {
                /*
                 * Add current iterated value to answer array if it is the first
                 * found intersected element or it is different from the
                 * previous found intersected element.
                 */
                addElementToAnswerArrayST(&answer_array_st, nums1[idx_1]);

                /* Update previous found intersected element. */
                previous_same_element = nums1[idx_1];
            }

            /* Increase both pointers by 1. */
            ++idx_1;
            ++idx_2;
        }
        else if (nums1[idx_1] < nums2[idx_2]) {
            /*
             * If current iterated value in the nums1 array is less than current
             * iterated value in the nums2 array, we need to increase the
             * pointer for nums1 array by 1 since that value will not show in
             * the rest of sections in the nums2 array.
             */
            ++idx_1;
        }
        else {
            /*
             * If current iterated value in the nums2 array is greater than
             * current iterated value in the nums2 array, we need to increase
             * the pointer for nums2 array by 1 since that value will not show
             * in the rest of sections in the nums1 array.
             */
            ++idx_2;
        }
    }

    (*returnSize) = (answer_array_st.next_available_idx);

    return (answer_array_st.array_ptr);
}
