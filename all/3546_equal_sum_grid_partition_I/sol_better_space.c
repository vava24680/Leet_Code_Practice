#include <stdbool.h>
#include <stdlib.h>

bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    if (0 == gridSize) {
        return false;
    }

    const int GRID_MATRIX_ROWS_NUMBER = gridSize;
    const int GRID_MATRIX_COLUMNS_NUMBER = (gridColSize[0]);

    bool result = false;
    long long total_sum = 0, accumulated_sum = 0;
    long long *data_blocks_array_ptr = (
        (long long*)calloc(
            GRID_MATRIX_ROWS_NUMBER + GRID_MATRIX_COLUMNS_NUMBER,
            sizeof(*data_blocks_array_ptr)
        )
    );
    long long *row_sum_array_ptr = data_blocks_array_ptr;
    long long *column_sum_array_ptr = (
        data_blocks_array_ptr + GRID_MATRIX_ROWS_NUMBER
    );

    for (int row_index = 0; row_index < GRID_MATRIX_ROWS_NUMBER; ++row_index) {
        for (
            int column_index = 0;
            column_index < GRID_MATRIX_COLUMNS_NUMBER;
            ++column_index
        ) {
            row_sum_array_ptr[row_index] += (grid[row_index][column_index]);
            column_sum_array_ptr[column_index] += (
                grid[row_index][column_index]
            );
            total_sum += (grid[row_index][column_index]);
        }
    }

    if (total_sum & 0x1) {
        /*
         * If total sum is an odd number, it is impossible that we can cut
         * the matrix into two parts with equal sum.
         */
        result = false;

        goto FINAL_CLEANUP;
    }

    accumulated_sum = 0;

    for (
        int column_index = 0;
        column_index < (GRID_MATRIX_COLUMNS_NUMBER - 1);
        ++column_index
    ) {
        accumulated_sum += (column_sum_array_ptr[column_index]);

        if (total_sum == (accumulated_sum << 1)) {
            result = true;

            goto FINAL_CLEANUP;
        }
    }

    accumulated_sum = 0;

    for (
        int row_index = 0;
        row_index < (GRID_MATRIX_ROWS_NUMBER - 1);
        ++row_index
    ) {
        accumulated_sum += (row_sum_array_ptr[row_index]);

        if (total_sum == (accumulated_sum << 1)) {
            result = true;

            goto FINAL_CLEANUP;
        }
    }

FINAL_CLEANUP:
    free(data_blocks_array_ptr);
    data_blocks_array_ptr = NULL;
    row_sum_array_ptr = NULL;
    column_sum_array_ptr = NULL;

    return result;
}
