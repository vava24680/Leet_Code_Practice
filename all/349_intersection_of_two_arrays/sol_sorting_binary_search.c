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

int findFirstGreaterThanOrEqualIndex(
    const int * const array_ptr,
    const int start_index,
    const int end_index,
    const int target_element
) {
    int left_index = start_index;
    int right_index = end_index;
    int middle_index = 0;

    while (left_index < right_index) {
        middle_index = (left_index + ((right_index - left_index) >> 1));

        if ((array_ptr[middle_index]) < target_element) {
            left_index = (middle_index + 1);
        }
        else {
            right_index = middle_index;
        }
    }

    return left_index;
}

int* intersection(
    int* nums1,
    int nums1Size,
    int* nums2,
    int nums2Size,
    int* returnSize
) {
    const int shorter_array_length = (
        (nums1Size < nums2Size) ? nums1Size : nums2Size
    );
    const int longer_array_length = (
        (nums1Size >= nums2Size) ? nums1Size : nums2Size
    );

    AnswerArrayST answer_array_st = {
        .array_ptr = NULL,
        .array_length = 0,
        .next_available_idx = 0,
    };
    int *shorter_array_ptr = ((nums1Size < nums2Size) ? nums1 : nums2);
    int *longer_array_ptr = ((nums1Size >= nums2Size) ? nums1 : nums2);
    int first_index_after_binary_search = 0;

    /* Sort the shorter array in the ascending order. */
    qsort(
        (void*)shorter_array_ptr,
        (size_t)shorter_array_length,
        sizeof(*shorter_array_ptr),
        &compareFunction
    );

    /* Sort the longer array in the ascending order. */
    qsort(
        (void*)longer_array_ptr,
        (size_t)longer_array_length,
        sizeof(*longer_array_ptr),
        &compareFunction
    );

    for (int i = 0; i < shorter_array_length; ++i) {
        if (i && ((shorter_array_ptr[i - 1]) == (shorter_array_ptr[i]))) {
            continue;
        }

        first_index_after_binary_search = findFirstGreaterThanOrEqualIndex(
            longer_array_ptr,
            0,
            longer_array_length,
            shorter_array_ptr[i]
        );

        if (
            (first_index_after_binary_search < longer_array_length)
            &&
            (
                (shorter_array_ptr[i])
                ==
                (longer_array_ptr[first_index_after_binary_search])
            )
        ) {
            addElementToAnswerArrayST(&answer_array_st, shorter_array_ptr[i]);
        }
    }

    (*returnSize) = (answer_array_st.next_available_idx);

    return (answer_array_st.array_ptr);
}
