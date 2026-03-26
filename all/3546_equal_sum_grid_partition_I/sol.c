#include <stdbool.h>
#include <stdlib.h>

bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    if (0 == gridSize) {
        return false;
    }

    const int GRID_MATRIX_ROWS_NUMBER = gridSize;
    const int GRID_MATRIX_COLUMNS_NUMBER = (gridColSize[0]);

    bool result = false;
    long long **prefix_sum_matrix_ptr = (
        (long long**)malloc(
            sizeof(*prefix_sum_matrix_ptr) * (GRID_MATRIX_ROWS_NUMBER + 1)
        )
    );
    long long *data_blocks_array_ptr = (
        (long long*)calloc(
            (GRID_MATRIX_ROWS_NUMBER + 1) * (GRID_MATRIX_COLUMNS_NUMBER + 1),
            sizeof(*data_blocks_array_ptr)
        )
    );

    for (int row_index = 0; row_index <= GRID_MATRIX_ROWS_NUMBER; ++row_index) {
        prefix_sum_matrix_ptr[row_index] = (
            data_blocks_array_ptr
            +
            (row_index * (GRID_MATRIX_COLUMNS_NUMBER + 1))
        );
    }

    for (int row_index = 0; row_index < GRID_MATRIX_ROWS_NUMBER; ++row_index) {
        for (
            int column_index = 0;
            column_index < GRID_MATRIX_COLUMNS_NUMBER;
            ++column_index
        ) {
            prefix_sum_matrix_ptr[row_index + 1][column_index + 1] = (
                (grid[row_index][column_index])
                +
                (prefix_sum_matrix_ptr[row_index + 1][column_index])
                +
                (prefix_sum_matrix_ptr[row_index][column_index + 1])
                -
                (prefix_sum_matrix_ptr[row_index][column_index])
            );
        }
    }

    if (
        (
            prefix_sum_matrix_ptr[
                GRID_MATRIX_ROWS_NUMBER
            ][
                GRID_MATRIX_COLUMNS_NUMBER
            ]
        )
        &
        0x1
    ) {
        /*
         * If total sum is an odd number, it is impossible that we can cut
         * the matrix into two parts with equal sum.
         */
        result = false;

        goto FINAL_CLEANUP;
    }

    for (
        int column_index = 0;
        column_index < (GRID_MATRIX_COLUMNS_NUMBER - 1);
        ++column_index
    ) {
        if (
            (
                (
                    prefix_sum_matrix_ptr[
                        GRID_MATRIX_ROWS_NUMBER
                    ][
                        column_index + 1
                    ]
                )
                <<
                1
            )
            ==
            (
                prefix_sum_matrix_ptr[
                    GRID_MATRIX_ROWS_NUMBER
                ][
                    GRID_MATRIX_COLUMNS_NUMBER
                ]
            )
        ) {
            result = true;

            goto FINAL_CLEANUP;
        }
    }

    for (
        int row_index = 0;
        row_index < (GRID_MATRIX_ROWS_NUMBER - 1);
        ++row_index
    ) {
        if (
            (
                (
                    prefix_sum_matrix_ptr[
                        row_index + 1
                    ][
                        GRID_MATRIX_COLUMNS_NUMBER
                    ]
                )
                <<
                1
            )
            ==
            (
                prefix_sum_matrix_ptr[
                    GRID_MATRIX_ROWS_NUMBER
                ][
                    GRID_MATRIX_COLUMNS_NUMBER
                ]
            )
        ) {
            result = true;

            goto FINAL_CLEANUP;
        }
    }

FINAL_CLEANUP:
    free(prefix_sum_matrix_ptr);
    prefix_sum_matrix_ptr = NULL;

    free(data_blocks_array_ptr);
    data_blocks_array_ptr = NULL;

    return result;
}
