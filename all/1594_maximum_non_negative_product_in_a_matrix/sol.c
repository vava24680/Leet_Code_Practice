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

    DPStatePairST **dp_state_matrix_ptr = (
        (DPStatePairST**)malloc(
            sizeof(*dp_state_matrix_ptr) * GRID_MATRIX_ROWS_NUMBER
        )
    );
    DPStatePairST *data_blocks_array_ptr = (
        (DPStatePairST*)malloc(
            sizeof(*data_blocks_array_ptr)
            *
            GRID_MATRIX_ROWS_NUMBER
            *
            GRID_MATRIX_COLUMNS_NUMBER
        )
    );

    for (int row_index = 0; row_index < GRID_MATRIX_ROWS_NUMBER; ++row_index) {
        dp_state_matrix_ptr[row_index] = (
            data_blocks_array_ptr + (row_index * GRID_MATRIX_COLUMNS_NUMBER)
        );
    }

    (dp_state_matrix_ptr[0][0]).maximum_product = grid[0][0];
    (dp_state_matrix_ptr[0][0]).minimum_product = grid[0][0];

    for (int row_index = 0; row_index < GRID_MATRIX_ROWS_NUMBER; ++row_index) {
        for (
            int column_index = 0;
            column_index < GRID_MATRIX_COLUMNS_NUMBER;
            ++column_index
        ) {
            if ((row_index > 0) && (column_index > 0)) {
                previous_cells_maximum_product = llmax(
                    (
                        (
                            dp_state_matrix_ptr[row_index][column_index - 1]
                        ).maximum_product
                    ),
                    (
                        (
                            dp_state_matrix_ptr[row_index - 1][column_index]
                        ).maximum_product
                    )
                );
                previous_cells_minimum_product = llmin(
                    (
                        (
                            dp_state_matrix_ptr[row_index][column_index - 1]
                        ).minimum_product
                    ),
                    (
                        (
                            dp_state_matrix_ptr[row_index - 1][column_index]
                        ).minimum_product
                    )
                );
            }
            else if (row_index > 0) {
                previous_cells_maximum_product = (
                    (
                        dp_state_matrix_ptr[row_index - 1][column_index]
                    ).maximum_product
                );
                previous_cells_minimum_product = (
                    (
                        dp_state_matrix_ptr[row_index - 1][column_index]
                    ).minimum_product
                );
            }
            else if (column_index > 0) {
                previous_cells_maximum_product = (
                    (
                        dp_state_matrix_ptr[row_index][column_index - 1]
                    ).maximum_product
                );
                previous_cells_minimum_product = (
                    (
                        dp_state_matrix_ptr[row_index][column_index - 1]
                    ).minimum_product
                );
            }
            else {
                continue;
            }

            current_cell_value = grid[row_index][column_index];

            if (current_cell_value >= 0) {
                (
                    (
                        dp_state_matrix_ptr[row_index][column_index]
                    ).maximum_product
                ) = (
                    ((long long)current_cell_value)
                    *
                    previous_cells_maximum_product
                );
                (
                    (
                        dp_state_matrix_ptr[row_index][column_index]
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
                        dp_state_matrix_ptr[row_index][column_index]
                    ).maximum_product
                ) = (
                    ((long long)current_cell_value)
                    *
                    previous_cells_minimum_product
                );
                (
                    (
                        dp_state_matrix_ptr[row_index][column_index]
                    ).minimum_product
                ) = (
                    ((long long)current_cell_value)
                    *
                    previous_cells_maximum_product
                );
            }
        }
    }

    maximum_product = (
        (
            dp_state_matrix_ptr[
                GRID_MATRIX_ROWS_NUMBER - 1
            ][
                GRID_MATRIX_COLUMNS_NUMBER - 1
            ]
        ).maximum_product
    );

    free(dp_state_matrix_ptr);
    dp_state_matrix_ptr = NULL;

    free(data_blocks_array_ptr);
    data_blocks_array_ptr = NULL;

    if (maximum_product < 0) {
        return -1;
    }

    return (int)(maximum_product % MODULO_LL);
}
