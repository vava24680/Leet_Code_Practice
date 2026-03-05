#include <stdlib.h>

int countTrailingConsecutiveZeros(const int * const row_ptr, const int length) {
    int trailing_consecutive_zeros_count = 0;

    for (int i = length - 1; i >= 0; --i) {
        if (row_ptr[i]) {
            break;
        }

        ++trailing_consecutive_zeros_count;
    }

    return trailing_consecutive_zeros_count;
}

int minSwaps(int** grid, int gridSize, int* gridColSize) {
    int minimum_swap_operations_count = 0;
    int *trailing_consecutive_zeros_array_ptr = (
        (int*)malloc(sizeof(*trailing_consecutive_zeros_array_ptr) * gridSize)
    );

    /* Count consecutive trailing 0 in each row. */
    for (int row_index = 0; row_index < gridSize; ++row_index) {
        trailing_consecutive_zeros_array_ptr[row_index] = (
            countTrailingConsecutiveZeros(
                grid[row_index],
                gridColSize[row_index]
            )
        );
    }

    for (int row_index = 0; row_index < gridSize; ++row_index) {
        int target_row_index = row_index;

        /*
         * Find the first target row that has enough consecutive trailing
         * zeros.
         */
        for (; target_row_index < gridSize; ++target_row_index) {
            if (
                trailing_consecutive_zeros_array_ptr[target_row_index]
                >=
                (gridSize - 1 - row_index)
            ) {
                break;
            }
        }

        if (gridSize == target_row_index) {
            minimum_swap_operations_count = -1;

            break;
        }

        /* Move the target row to row i by swaping two adjacent rows at a time. */
        for (int i = target_row_index; i > row_index; --i) {
            int tmp = trailing_consecutive_zeros_array_ptr[i];
            trailing_consecutive_zeros_array_ptr[i] = (
                trailing_consecutive_zeros_array_ptr[i - 1]
            );
            trailing_consecutive_zeros_array_ptr[i - 1] = tmp;
        }

        /* Accumulate swaps count. */
        minimum_swap_operations_count += (target_row_index - row_index);
    }

    free(trailing_consecutive_zeros_array_ptr);
    trailing_consecutive_zeros_array_ptr = NULL;

    return minimum_swap_operations_count;
}
