#include <stddef.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int current_common_numbers_count = 0;

    int *answer_array_ptr = (int*)malloc(sizeof(*answer_array_ptr) * ASize);
    int *values_counter_array_ptr = (
        (int*)calloc(ASize + 1, sizeof(*values_counter_array_ptr))
    );

    for (int i = 0; i < ASize; ++i) {
        (values_counter_array_ptr[A[i]]) += 1;

        if (2 == (values_counter_array_ptr[A[i]])) {
            /*
             * If a value's count is 2, it means it occurs in both of A array
             * and B array, we can increase common numbers count by 1.
             */
            ++current_common_numbers_count;
        }

        (values_counter_array_ptr[B[i]]) += 1;

        if (2 == (values_counter_array_ptr[B[i]])) {
            /*
             * If a value's count is 2, it means it occurs in both of A array
             * and B array, we can increase common numbers count by 1.
             */
            ++current_common_numbers_count;
        }

        answer_array_ptr[i] = current_common_numbers_count;
    }

    free(values_counter_array_ptr);
    values_counter_array_ptr = NULL;

    (*returnSize) = ASize;

    return answer_array_ptr;
}
