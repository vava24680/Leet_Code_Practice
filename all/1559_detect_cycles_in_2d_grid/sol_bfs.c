#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#define DIRECTIONS_COUNT (4)

typedef struct {
    int current_row_index;
    int current_column_index;
    int previous_row_index;
    int previous_column_index;
} CellInfoST;

typedef struct {
    CellInfoST *array_ptr;
    int array_length;
    int previous_read_index;
    int previous_write_index;
} FixedSizeCellInfoSTQueueST;

static bool isQueueEmpty(
    const FixedSizeCellInfoSTQueueST *fixed_size_cell_info_st_queue_st_ptr
) {
    return (
        (fixed_size_cell_info_st_queue_st_ptr->previous_read_index)
        ==
        (fixed_size_cell_info_st_queue_st_ptr->previous_write_index)
    );
}

static bool isQueueFull(
    const FixedSizeCellInfoSTQueueST *fixed_size_cell_info_st_queue_st_ptr
) {
    return (
        (fixed_size_cell_info_st_queue_st_ptr->previous_read_index)
        ==
        (
            ((fixed_size_cell_info_st_queue_st_ptr->previous_write_index) + 1)
            %
            (fixed_size_cell_info_st_queue_st_ptr->array_length)
        )
    );
}

static bool enqueCellInfoST(
    FixedSizeCellInfoSTQueueST *fixed_size_cell_info_st_queue_st_ptr,
    CellInfoST *cell_info_st_ptr
) {
    if (isQueueFull(fixed_size_cell_info_st_queue_st_ptr)) {
        return false;
    }

    int write_index = (
        ((fixed_size_cell_info_st_queue_st_ptr->previous_write_index) + 1)
        %
        (fixed_size_cell_info_st_queue_st_ptr->array_length)
    );

    (fixed_size_cell_info_st_queue_st_ptr->array_ptr)[write_index] = (
        *cell_info_st_ptr
    );

    (fixed_size_cell_info_st_queue_st_ptr->previous_write_index) = write_index;

    return true;
}

static bool popFromCellInfoSTQueueST(
    FixedSizeCellInfoSTQueueST *fixed_size_cell_info_st_queue_st_ptr,
    CellInfoST *cell_info_st_ptr
) {
    if (isQueueEmpty(fixed_size_cell_info_st_queue_st_ptr)) {
        return false;
    }

    int read_index = (
        ((fixed_size_cell_info_st_queue_st_ptr->previous_read_index) + 1)
        %
        (fixed_size_cell_info_st_queue_st_ptr->array_length)
    );

    (*cell_info_st_ptr) = (
        (fixed_size_cell_info_st_queue_st_ptr->array_ptr)[read_index]
    );

    (fixed_size_cell_info_st_queue_st_ptr->previous_read_index) = read_index;

    return true;
}

static bool detectCycleVisBFS(
    FixedSizeCellInfoSTQueueST *fixed_size_cell_info_st_queue_st_ptr,
    bool **visited_matrix_ptr,
    const char * const * grid_ptr,
    const int start_row_index,
    const int start_column_index,
    const int GRID_ROWS_NUMBER,
    const int GRID_COLUMNS_NUMBER
) {
    static const int row_movements_array[DIRECTIONS_COUNT] = {-1, 1, 0, 0};
    static const int column_movements_array[DIRECTIONS_COUNT] = {0, 0, -1, 1};
    const int start_cell_value = (
        grid_ptr[start_row_index][start_column_index]
    );

    int new_row_index, new_column_index;
    CellInfoST cell_info_st = {
        .current_row_index = start_row_index,
        .current_column_index = start_column_index,
        .previous_row_index = start_row_index,
        .previous_column_index = start_column_index,
    };
    CellInfoST new_cell_info_st;
    (fixed_size_cell_info_st_queue_st_ptr->previous_read_index) = 0;
    (fixed_size_cell_info_st_queue_st_ptr->previous_write_index) = 0;

    /* Mark the starting cell as visited. */
    visited_matrix_ptr[start_row_index][start_column_index] = true;

    /* Enque starting cell info. */
    enqueCellInfoST(fixed_size_cell_info_st_queue_st_ptr, &cell_info_st);

    while (!isQueueEmpty(fixed_size_cell_info_st_queue_st_ptr)) {
        popFromCellInfoSTQueueST(
            fixed_size_cell_info_st_queue_st_ptr,
            &cell_info_st
        );

        for (int i = 0; i < DIRECTIONS_COUNT; ++i) {
            new_row_index = (
                (cell_info_st.current_row_index) + row_movements_array[i]
            );
            new_column_index = (
                (cell_info_st.current_column_index)
                +
                (column_movements_array[i])
            );

            if (
                (new_row_index < 0)
                ||
                (new_row_index >= GRID_ROWS_NUMBER)
                ||
                (new_column_index < 0)
                ||
                (new_column_index >= GRID_COLUMNS_NUMBER)
            ) {
                /*
                 * Continue to next new row index and new column index
                 * if current one is invalid.
                 */
                continue;
            }

            if (
                start_cell_value
                !=
                (grid_ptr[new_row_index][new_column_index])
            ) {
                /*
                 * Continue to next new row index and new column index if the new
                 * cell's value is not matched with the start cell value.
                 */
                continue;
            }

            if (visited_matrix_ptr[new_row_index][new_column_index]) {
                if (
                    ((cell_info_st.previous_row_index) != new_row_index)
                    ||
                    ((cell_info_st.previous_column_index) != new_column_index)
                ) {
                    /*
                     * If the following conditions are met, it means there is
                     * a valid cycle in the given grid.
                     * 1. New row index and new column index does not equal
                     *    to the previous row index and previous column index.
                     * 2. New cell is already visited.
                     */
                    return true;
                }

                /*
                 * Continue to next new row index and new column index if new
                 * cell is already visited.
                 */
                continue;
            }

            /* Mark new cell as visited. */
            visited_matrix_ptr[new_row_index][new_column_index] = true;

            /* Enque new cell's information. */
            (new_cell_info_st.previous_row_index) = (
                cell_info_st.current_row_index
            );
            (new_cell_info_st.previous_column_index) = (
                cell_info_st.current_column_index
            );
            (new_cell_info_st.current_row_index) = new_row_index;
            (new_cell_info_st.current_column_index) = new_column_index;

            enqueCellInfoST(
                fixed_size_cell_info_st_queue_st_ptr,
                &new_cell_info_st
            );
        }
    }

    return false;
}

bool containsCycle(char** grid, int gridSize, int* gridColSize) {
    if (0 == gridSize) {
        return false;
    }

    const int GRID_ROWS_NUMBER = gridSize;
    const int GRID_COLUMNS_NUMBER = (gridColSize[0]);

    bool is_a_cycle_found = false;
    FixedSizeCellInfoSTQueueST fixed_size_cell_info_st_queue_st = {
        .previous_read_index = 0,
        .previous_write_index = 0,
    };
    bool **visited_matrix_ptr = (
        (bool**)malloc(sizeof(*visited_matrix_ptr) * GRID_ROWS_NUMBER)
    );
    bool *data_blocks_array_ptr = (
        (bool*)calloc(
            GRID_ROWS_NUMBER * GRID_COLUMNS_NUMBER,
            sizeof(*data_blocks_array_ptr)
        )
    );

    (fixed_size_cell_info_st_queue_st.array_length) = (
        (GRID_ROWS_NUMBER * GRID_COLUMNS_NUMBER) + 1
    );
    (fixed_size_cell_info_st_queue_st.array_ptr) = (
        (CellInfoST*)malloc(
            sizeof(*(fixed_size_cell_info_st_queue_st.array_ptr))
            *
            (fixed_size_cell_info_st_queue_st.array_length)
        )
    );

    for (int row_index = 0; row_index < GRID_ROWS_NUMBER; ++row_index) {
        visited_matrix_ptr[row_index] = (
            data_blocks_array_ptr + (row_index * GRID_COLUMNS_NUMBER)
        );
    }

    for (int row_index = 0; row_index < GRID_ROWS_NUMBER; ++row_index) {
        for (
            int column_index = 0;
            column_index < GRID_COLUMNS_NUMBER;
            ++column_index
        ) {
            if (visited_matrix_ptr[row_index][column_index]) {
                continue;
            }

            if (
                detectCycleVisBFS(
                    &fixed_size_cell_info_st_queue_st,
                    visited_matrix_ptr,
                    (const char * const *)grid,
                    row_index,
                    column_index,
                    GRID_ROWS_NUMBER, GRID_COLUMNS_NUMBER
                )
            ) {
                is_a_cycle_found = true;

                goto FINAL_CLEANUP;
            }
        }
    }

FINAL_CLEANUP:
    free(fixed_size_cell_info_st_queue_st.array_ptr);
    (fixed_size_cell_info_st_queue_st.array_ptr) = NULL;

    free(visited_matrix_ptr);
    visited_matrix_ptr = NULL;

    free(data_blocks_array_ptr);
    data_blocks_array_ptr = NULL;

    return is_a_cycle_found;
}
