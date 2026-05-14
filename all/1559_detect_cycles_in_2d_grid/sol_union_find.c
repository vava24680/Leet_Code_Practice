#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#define DIRECTIONS_COUNT (2)

static int unionFindFind(
    int *parents_array_ptr,
    const int parents_array_length,
    const int i
) {
    if (i >= parents_array_length) {
        return -1;
    }

    int root = i;
    int current_i = i;
    int original_parent;

    /* Find root of a given cell. */
    while (root != (parents_array_ptr[root])) {
        root = (parents_array_ptr[root]);
    }

    /*
     * Do path compresion to make all the nodes that have same ancestor point to
     * the ancestor directly.
     */
    while (root != (parents_array_ptr[current_i])) {
        original_parent = (parents_array_ptr[current_i]);
        (parents_array_ptr[current_i]) = root;
        current_i = original_parent;
    }

    return root;
}

static bool unionFindUnion(
    int *parents_array_ptr,
    const int parents_array_length,
    const int i,
    const int j
) {
    if ((i >= parents_array_length) || (j >= parents_array_length)) {
        return false;
    }

    const int root_of_i = unionFindFind(
        parents_array_ptr,
        parents_array_length,
        i
    );
    const int root_of_j = unionFindFind(
        parents_array_ptr,
        parents_array_length,
        j
    );

    parents_array_ptr[root_of_j] = root_of_i;

    return true;
}

bool containsCycle(char** grid, int gridSize, int* gridColSize) {
    if (0 == gridSize) {
        return false;
    }

    static const int row_movements_array[DIRECTIONS_COUNT] = {1, 0};
    static const int column_movements_array[DIRECTIONS_COUNT] = {0, 1};
    const int GRID_ROWS_NUMBER = gridSize;
    const int GRID_COLUMNS_NUMBER = (gridColSize[0]);
    const int PARENTS_ARRAY_LENGTH = (GRID_ROWS_NUMBER * GRID_COLUMNS_NUMBER);

    bool is_a_cycle_found = false;
    int new_row_index, new_column_index;
    int current_cell_flatted_index, new_cell_flatted_index;
    int *parents_array_ptr = (
        (int*)malloc(sizeof(*parents_array_ptr) * PARENTS_ARRAY_LENGTH)
    );

    /* Initialize parents array. */
    for (int i = 0; i < (GRID_ROWS_NUMBER * GRID_COLUMNS_NUMBER); ++i) {
        parents_array_ptr[i] = i;
    }

    /*
     * Try every cell in the grid and use unio find to detect if a cycle
     * exists in the given grid.
     *
     * Check notes for details.
     */
    for (int row_index = 0; row_index < GRID_ROWS_NUMBER; ++row_index) {
        for (
            int column_index = 0;
            column_index < GRID_COLUMNS_NUMBER;
            ++column_index
        ) {
            current_cell_flatted_index = (
                (row_index * GRID_COLUMNS_NUMBER) + column_index
            );

            for (int i = 0; i < DIRECTIONS_COUNT; ++i) {
                new_row_index = (row_index + row_movements_array[i]);
                new_column_index = (column_index + column_movements_array[i]);

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

                new_cell_flatted_index = (
                    (new_row_index * GRID_COLUMNS_NUMBER) + new_column_index
                );

                if (
                    (grid[row_index][column_index])
                    !=
                    (grid[new_row_index][new_column_index])
                ) {
                    /*
                     * Continue to next new row index and new column index if
                     * the new cell's value is not matched with current cell
                     * value.
                     */
                    continue;
                }

                if (
                    unionFindFind(
                        parents_array_ptr,
                        PARENTS_ARRAY_LENGTH,
                        current_cell_flatted_index
                    )
                    ==
                    unionFindFind(
                        parents_array_ptr,
                        PARENTS_ARRAY_LENGTH,
                        new_cell_flatted_index
                    )
                ) {
                    /*
                     * If two cells have same ancestor, they are in the same
                     * connected component, which means by connecting these
                     * two cells together can result in a cycle.
                     */
                    is_a_cycle_found = true;

                    goto FINAL_CLEANUP;
                }
                else {
                    /*
                     * Union the current cell and the new cell if they do not
                     * have same ancestor yet.
                     */
                    unionFindUnion(
                        parents_array_ptr,
                        PARENTS_ARRAY_LENGTH,
                        current_cell_flatted_index,
                        new_cell_flatted_index
                    );
                }
            }
        }
    }

FINAL_CLEANUP:
    free(parents_array_ptr);
    parents_array_ptr = NULL;

    return is_a_cycle_found;
}
