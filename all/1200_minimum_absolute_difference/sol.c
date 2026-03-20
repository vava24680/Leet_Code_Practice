#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct AnswerArrayStruct {
    int **array_ptr;
    int array_size;
    int next_available_index;
} AnswerArrayST;

int compareFunction(const void *p1, const void *p2) {
    const int i1 = (*((const int*)p1));
    const int i2 = (*((const int*)p2));

    return ((i1 > i2) - (i1 < i2));
}

bool addPairOfIntegersToAnswerArrayST(
    AnswerArrayST * const answer_array_st_ptr,
    const int first_integer,
    const int second_integer
) {
    int new_array_size = 0;
    void *tmp_ptr = NULL;

    if (
        (answer_array_st_ptr->next_available_index)
        >=
        (answer_array_st_ptr->array_size)
    ) {
        if (!(answer_array_st_ptr->array_size)) {
            new_array_size = 4;
        }
        else {
            new_array_size = ((answer_array_st_ptr->array_size) << 1);
        }

        tmp_ptr = realloc(
            answer_array_st_ptr->array_ptr,
            sizeof(*(answer_array_st_ptr->array_ptr)) * new_array_size
        );

        if (NULL == tmp_ptr) {
            /* Let caller decide what to do if memory allocation is failed. */
            return false;
        }

        (answer_array_st_ptr->array_ptr) = (int**)tmp_ptr;
        (answer_array_st_ptr->array_size) = new_array_size;
    }

    tmp_ptr = malloc(sizeof(**(answer_array_st_ptr->array_ptr)) << 1);

    if (NULL == tmp_ptr) {
        return false;
    }

    (answer_array_st_ptr->array_ptr)[
        answer_array_st_ptr->next_available_index
    ] = ((int*)tmp_ptr);

    (answer_array_st_ptr->array_ptr)[
        answer_array_st_ptr->next_available_index
    ][
        0
    ] = first_integer;
    (answer_array_st_ptr->array_ptr)[
        answer_array_st_ptr->next_available_index
    ][
        1
    ] = second_integer;

    ++(answer_array_st_ptr->next_available_index);

    return true;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** minimumAbsDifference(
    int* arr,
    int arrSize,
    int* returnSize,
    int** returnColumnSizes
) {
    int minimum_absolute_difference = INT_MAX;
    AnswerArrayST answer_array_st = {
        .array_ptr = NULL,
        .array_size = 0,
        .next_available_index = 0,
    };

    /* Sort the given array first. */
    qsort(arr, arrSize, sizeof(*arr), &compareFunction);

    /*
     * Find the minimum absolute difference between any two elements in the
     * given array.
     */
    for (int i = 1; i < arrSize; ++i) {
        if (((arr[i]) - (arr[i - 1])) < minimum_absolute_difference) {
            minimum_absolute_difference = ((arr[i]) - (arr[i - 1]));
        }
    }

    /*
     * Find all pairs of elements whose absolute difference is the minimum
     * absolute difference.
     */
    for (int i = 1; i < arrSize; ++i) {
        if (((arr[i]) - (arr[i - 1])) == minimum_absolute_difference) {
            if (
                !addPairOfIntegersToAnswerArrayST(
                    &answer_array_st,
                    arr[i - 1],
                    arr[i]
                )
            ) {
                for (int i = 0; i < (answer_array_st.array_size); ++i) {
                    free(answer_array_st.array_ptr[i]);
                }

                free(answer_array_st.array_ptr);
                answer_array_st.array_ptr = NULL;

                (*returnSize) = 0;

                return NULL;
            }
        }
    }

    (*returnSize) = answer_array_st.next_available_index;
    (*returnColumnSizes) = (int*)malloc(
        sizeof(**returnColumnSizes) * (answer_array_st.next_available_index)
    );

    for (int i = 0; i < (answer_array_st.next_available_index); ++i) {
        (*returnColumnSizes)[i] = 2;
    }

    return answer_array_st.array_ptr;
}
