#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#define DIRECTIONS_COUNT (4)

static bool checkCycleViaDFS(
    bool **visited_matrix_ptr,
    const char * const * grid_ptr,
    const char start_cell_value,
    const int previous_row_index,
    const int previous_column_index,
    const int current_row_index,
    const int current_column_index,
    const int GRID_ROWS_NUMBER,
    const int GRID_COLUMNS_NUMBER
) {
    static const int row_movements_array[DIRECTIONS_COUNT] = {-1, 1, 0, 0};
    static const int column_movements_array[DIRECTIONS_COUNT] = {0, 0, -1, 1};

    int new_row_index = 0;
    int new_column_index = 0;

    /* Mark current cell is visited. */
    visited_matrix_ptr[current_row_index][current_column_index] = true;

    /* Use DFS to try every possible direction to check if there is valid cycle. */
    for (int i = 0; i < DIRECTIONS_COUNT; ++i) {
        new_row_index = (current_row_index + (row_movements_array[i]));
        new_column_index = (current_column_index + (column_movements_array[i]));

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
                (previous_row_index != new_row_index)
                ||
                (previous_column_index != new_column_index)
            ) {
                /*
                 * If the following conditions are met, it means there is a valid
                 * cycle in the given grid.
                 * 1. New row index and new column index does not equal to the
                 *    previous row index and previous column index.
                 * 2. New cell is already visited.
                 */
                return true;
            }

            /*
             * Continue to next new row index and new column index if new cell
             * is already visited.
             */
            continue;
        }

        if (
            checkCycleViaDFS(
                visited_matrix_ptr,
                grid_ptr,
                start_cell_value,
                current_row_index,
                current_column_index,
                new_row_index,
                new_column_index,
                GRID_ROWS_NUMBER,
                GRID_COLUMNS_NUMBER
            )
        ) {
            /* Return true if following DFS detects a cycle in the given grid. */
            return true;
        }
    }

    /*
     * Do not set current cell as unvisited here since we do not need to
     * take other cell in the current path as start cell since there does
     * not exist a cycle.
     */

    return false;
}

bool containsCycle(char** grid, int gridSize, int* gridColSize) {
    const int GRID_ROWS_NUMBER = gridSize;
    const int GRID_COLUMNS_NUMBER = (gridColSize[0]);

    bool is_a_cycle_found = false;
    bool **visited_matrix_ptr = (
        (bool**)malloc(sizeof(*visited_matrix_ptr) * GRID_ROWS_NUMBER)
    );
    bool *data_blocks_array_ptr = (
        (bool*)calloc(
            GRID_ROWS_NUMBER * GRID_COLUMNS_NUMBER,
            sizeof(*data_blocks_array_ptr)
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
            /*
             * Try every unvisited cell in the given grid as start point and
             * check if there is a valid cycle.
             */
            if (
                (false == (visited_matrix_ptr[row_index][column_index]))
                &&
                checkCycleViaDFS(
                    visited_matrix_ptr,
                    (const char * const *)grid,
                    grid[row_index][column_index],
                    row_index,
                    column_index,
                    row_index,
                    column_index,
                    GRID_ROWS_NUMBER,
                    GRID_COLUMNS_NUMBER
                )
            ) {
                is_a_cycle_found = true;

                goto FINAL_CLEANUP;
            }
        }
    }

FINAL_CLEANUP:
    free(visited_matrix_ptr);
    visited_matrix_ptr = NULL;

    free(data_blocks_array_ptr);
    data_blocks_array_ptr = NULL;

    return is_a_cycle_found;
}
