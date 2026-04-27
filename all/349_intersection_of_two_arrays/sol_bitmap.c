#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_ELEMENT_VALUE (1000)
#define NUMBER_OF_UINT64_NEEDED(n) (((n) + 1 + (64 - 1)) / 64)
#define SET_BIT_IN_BITMAP(bitmap, x) (((bitmap)[(x) / 64]) |= ((UINT64_C(1)) << ((x) % 64)))
#define TEST_BIT_IN_BITMAP(bitmap, x) (((bitmap)[(x) / 64]) & ((UINT64_C(1))<< ((x) % 64)))
#define CLEAR_BIT_IN_BITMAP(bitmap, x) (((bitmap)[(x) / 64]) &= (~((UINT64_C(1)) << ((x) % 64))))

typedef struct AnswerArrayStruct {
    int *array_ptr;
    int array_length;
    int next_available_idx;
} AnswerArrayST;

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
    uint64_t bitmap[NUMBER_OF_UINT64_NEEDED(MAX_ELEMENT_VALUE)];
    AnswerArrayST answer_array_st = {
        .array_ptr = NULL,
        .array_length = 0,
        .next_available_idx = 0,
    };

    memset(
        (void*)(&(bitmap[0])),
        0,
        NUMBER_OF_UINT64_NEEDED(MAX_ELEMENT_VALUE) * sizeof(bitmap[0])
    );

    for (int i = 0; i < nums1Size; ++i) {
        /* Iterate all values in the nums1 array to set up the bitmap array. */
        SET_BIT_IN_BITMAP(bitmap, nums1[i]);
    }

    for (int i = 0; i < nums2Size; ++i) {
        if (TEST_BIT_IN_BITMAP(bitmap, nums2[i])) {
            addElementToAnswerArrayST(&answer_array_st, nums2[i]);

            /*
             * After finding a new intersected value, we clear the
             * corresponding bit in the bitmap to avoid repeated matching.
             */
            CLEAR_BIT_IN_BITMAP(bitmap, nums2[i]);
        }
    }

    (*returnSize) = (answer_array_st.next_available_idx);

    return (answer_array_st.array_ptr);
}
