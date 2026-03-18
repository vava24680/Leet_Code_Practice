#include <stddef.h>
#include <stdlib.h>

int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {
    if ((0 == gridSize) || (grid[0][0] > k)) {
        return 0;
    }

    const int GRID_MATRIX_ROWS_NUMBER = gridSize;
    const int GRID_MATRIX_COLUMNS_NUMBER = gridColSize[0];

    int valid_submatrices_count = 0;
    int *data_blocks_array_ptr = (
        (int*)calloc(
            (GRID_MATRIX_ROWS_NUMBER + 1) * (GRID_MATRIX_COLUMNS_NUMBER + 1),
            sizeof(*data_blocks_array_ptr)
        )
    );
    int **prefix_sum_matrix_ptr = (
        (int**)malloc(
            sizeof(*prefix_sum_matrix_ptr) * (GRID_MATRIX_ROWS_NUMBER + 1)
        )
    );

    if ((NULL == data_blocks_array_ptr) || (NULL == prefix_sum_matrix_ptr)) {
        free(data_blocks_array_ptr);
        data_blocks_array_ptr = NULL;

        free(prefix_sum_matrix_ptr);
        prefix_sum_matrix_ptr = NULL;

        return 0;
    }

    for (
        int row_index = 0;
        row_index < (GRID_MATRIX_ROWS_NUMBER + 1);
        ++row_index
    ) {
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
            prefix_sum_matrix_ptr[row_index + 1][column_index + 1] += (
                prefix_sum_matrix_ptr[row_index][column_index + 1]
                +
                prefix_sum_matrix_ptr[row_index + 1][column_index]
                -
                prefix_sum_matrix_ptr[row_index][column_index]
                +
                grid[row_index][column_index]
            );

            if (prefix_sum_matrix_ptr[row_index + 1][column_index + 1] > k) {
                break;
            }

            ++valid_submatrices_count;
        }
    }

    free(data_blocks_array_ptr);
    data_blocks_array_ptr = NULL;

    free(prefix_sum_matrix_ptr);
    prefix_sum_matrix_ptr = NULL;

    return valid_submatrices_count;
}
