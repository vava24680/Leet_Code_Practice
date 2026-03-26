#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct {
    long long maximum_product;
    long long minimum_product;
} DPStatePairST;

static const long long MODULO_LL = 1000000007LL;

static inline long long llmax(const long long l1, const long long l2) {
    return ((l1 > l2) ? l1 : l2);
}

static inline long long llmin(const long long l1, const long long l2) {
    return ((l1 < l2) ? l1 : l2);
}

int maxProductPath(int** grid, int gridSize, int* gridColSize) {
    if (0 == gridSize) {
        return 0;
    }

    const int GRID_MATRIX_ROWS_NUMBER = gridSize;
    const int GRID_MATRIX_COLUMNS_NUMBER = (gridColSize[0]);

    long long maximum_product = LLONG_MIN;
    long long previous_cells_maximum_product = 0LL;
    long long previous_cells_minimum_product = 0LL;
    int current_cell_value = 0;

    DPStatePairST *data_blocks_array_ptr = (
        (DPStatePairST*)malloc(
            sizeof(*data_blocks_array_ptr)
            *
            2
            *
            GRID_MATRIX_COLUMNS_NUMBER
        )
    );
    DPStatePairST *previous_row_dp_state_array_ptr = data_blocks_array_ptr;
    DPStatePairST *current_row_dp_state_array_ptr = (
        data_blocks_array_ptr + GRID_MATRIX_COLUMNS_NUMBER
    );
    DPStatePairST *tmp_ptr = NULL;

    /* Construct the DP state for the first row. */
    ((previous_row_dp_state_array_ptr[0]).maximum_product) = (grid[0][0]);
    ((previous_row_dp_state_array_ptr[0]).minimum_product) = (grid[0][0]);

    for (
        int column_index = 1;
        column_index < GRID_MATRIX_COLUMNS_NUMBER;
        ++column_index
    ) {
        ((previous_row_dp_state_array_ptr[column_index]).maximum_product) = (
            ((previous_row_dp_state_array_ptr[column_index - 1]).maximum_product)
            *
            (grid[0][column_index])
        );
        ((previous_row_dp_state_array_ptr[column_index]).minimum_product) = (
            ((previous_row_dp_state_array_ptr[column_index - 1]).minimum_product)
            *
            (grid[0][column_index])
        );
    }

    /* Construct the DP state for the rest of rows except the first row. */
    for (int row_index = 1; row_index < GRID_MATRIX_ROWS_NUMBER; ++row_index) {
        /* Construct the DP state for the first column in each row. */
        ((current_row_dp_state_array_ptr[0]).maximum_product) = (
            ((previous_row_dp_state_array_ptr[0]).maximum_product)
            *
            (grid[row_index][0])
        );
        ((current_row_dp_state_array_ptr[0]).minimum_product) = (
            ((previous_row_dp_state_array_ptr[0]).minimum_product)
            *
            (grid[row_index][0])
        );

        /*
         * Construct the DP state for rest of columns except the first column
         * within a row.
         */
        for (
            int column_index = 1;
            column_index < GRID_MATRIX_COLUMNS_NUMBER;
            ++column_index
        ) {
            current_cell_value = grid[row_index][column_index];
            previous_cells_maximum_product = llmax(
                (
                    (
                        current_row_dp_state_array_ptr[column_index - 1]
                    ).maximum_product
                ),
                (
                    (
                        previous_row_dp_state_array_ptr[column_index]
                    ).maximum_product
                )
            );
            previous_cells_minimum_product = llmin(
                (
                    (
                        current_row_dp_state_array_ptr[column_index - 1]
                    ).minimum_product
                ),
                (
                    (
                        previous_row_dp_state_array_ptr[column_index]
                    ).minimum_product
                )
            );

            if (current_cell_value >= 0) {
                (
                    (
                        current_row_dp_state_array_ptr[column_index]
                    ).maximum_product
                ) = (
                    ((long long)current_cell_value)
                    *
                    previous_cells_maximum_product
                );
                (
                    (
                        current_row_dp_state_array_ptr[column_index]
                    ).minimum_product
                ) = (
                    ((long long)current_cell_value)
                    *
                    previous_cells_minimum_product
                );
            }
            else {
                (
                    (
                        current_row_dp_state_array_ptr[column_index]
                    ).maximum_product
                ) = (
                    ((long long)current_cell_value)
                    *
                    previous_cells_minimum_product
                );
                (
                    (
                        current_row_dp_state_array_ptr[column_index]
                    ).minimum_product
                ) = (
                    ((long long)current_cell_value)
                    *
                    previous_cells_maximum_product
                );
            }
        }

        tmp_ptr = previous_row_dp_state_array_ptr;
        previous_row_dp_state_array_ptr = current_row_dp_state_array_ptr;
        current_row_dp_state_array_ptr = tmp_ptr;
    }

    maximum_product = (
        (
            previous_row_dp_state_array_ptr[
                GRID_MATRIX_COLUMNS_NUMBER - 1
            ]
        ).maximum_product
    );

    free(data_blocks_array_ptr);
    data_blocks_array_ptr = NULL;
    previous_row_dp_state_array_ptr = NULL;
    current_row_dp_state_array_ptr = NULL;

    if (maximum_product < 0) {
        return -1;
    }

    return (int)(maximum_product % MODULO_LL);
}
