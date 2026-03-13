#include <stddef.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int *answer_array_ptr = (
        (int*)calloc(temperaturesSize, sizeof(*answer_array_ptr))
    );
    int *indices_stack_array_ptr = (
        (int*)malloc(sizeof(*indices_stack_array_ptr) * temperaturesSize)
    );
    int stack_next_available_index = 0, popped_index = 0;

    if ((NULL == answer_array_ptr) || (NULL == indices_stack_array_ptr)) {
        free(answer_array_ptr);
        answer_array_ptr = NULL;

        free(indices_stack_array_ptr);
        indices_stack_array_ptr = NULL;

        (*returnSize) = 0;

        return NULL;
    }

    for (int i = 0; i < temperaturesSize; ++i) {
        while (
            (stack_next_available_index > 0)
            &&
            (
                temperatures[i]
                >
                temperatures[indices_stack_array_ptr[stack_next_available_index - 1]]
            )
        ) {
            /*
             * Pop out the index if current iterated temperature is larger than
             * the temperature indexed by the popped out index.
             */
            popped_index = (
                indices_stack_array_ptr[stack_next_available_index - 1]
            );

            /* Set answer for the temperature indexed by the popped out index. */
            answer_array_ptr[popped_index] = (i - popped_index);

            --stack_next_available_index;
        }

        /*
         * Add current iterated index to the indices stack since current
         * iterated temperature still does not have the next larger temperature.
         */
        indices_stack_array_ptr[stack_next_available_index] = i;
        ++stack_next_available_index;
    }

    (*returnSize) = temperaturesSize;

    free(indices_stack_array_ptr);
    indices_stack_array_ptr = NULL;

    return answer_array_ptr;
}
