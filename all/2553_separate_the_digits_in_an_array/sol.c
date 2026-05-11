#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int *array_ptr;
    int array_length;
    int next_available_index;
} DynamicIntArrayST;

bool addNewValueToDynamicIntArrayST(
    DynamicIntArrayST * dynamic_int_array_st_ptr,
    const int new_value
) {
    int new_array_length;
    int *new_array_ptr = NULL;

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

        (dynamic_int_array_st_ptr->array_ptr) = new_array_ptr;
        (dynamic_int_array_st_ptr->array_length) = new_array_length;
    }

    (dynamic_int_array_st_ptr->array_ptr)[
        dynamic_int_array_st_ptr->next_available_index
    ] = new_value;
    ++(dynamic_int_array_st_ptr->next_available_index);

    return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* separateDigits(int* nums, int numsSize, int* returnSize) {
    DynamicIntArrayST answer_array_st = {
        .array_ptr = NULL,
        .array_length = 0,
        .next_available_index = 0,
    };
    int digits_length = 0;
    char num_string[11];

    for (int i = 0; i < numsSize; ++i) {
        digits_length = snprintf(
            &(num_string[0]),
            sizeof(num_string) / sizeof(num_string[0]),
            "%d",
            nums[i]
        );

        if (digits_length >= (sizeof(num_string) / sizeof(num_string[0]))) {
            continue;
        }

        for (int j = 0; j < digits_length; ++j) {
            if (
                false
                ==
                addNewValueToDynamicIntArrayST(
                    &answer_array_st,
                    ((int)num_string[j]) - ((int)'0')
                )
            ) {
                free(answer_array_st.array_ptr);
                (answer_array_st.array_length) = 0;
                (answer_array_st.next_available_index) = 0;

                goto FINAL;
            }
        }
    }

FINAL:
    (*returnSize) = (answer_array_st.next_available_index);

    return (answer_array_st.array_ptr);
}
