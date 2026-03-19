#include <stddef.h>
#include <stdlib.h>

typedef struct {
    int x_characters_count;
    int y_characters_count;
} CharactersCountPairST;

int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize) {
    if (0 == gridSize) {
        return 0;
    }

    const int GRID_MATRIX_ROWS_NUMBER = gridSize;
    const int GRID_MATRIX_COLUMNS_NUMBER = gridColSize[0];

    int valid_submatrices_count = 0;
    int total_x_characters_count = 0;
    int total_y_characters_count = 0;
    CharactersCountPairST *data_blocks_array_ptr = (
        (CharactersCountPairST*)calloc(
            (GRID_MATRIX_COLUMNS_NUMBER + 1) << 1,
            sizeof(*data_blocks_array_ptr)
        )
    );
    CharactersCountPairST *previous_row_prefix_sum_array_ptr = NULL;
    CharactersCountPairST *current_row_prefix_sum_array_ptr = NULL;
    CharactersCountPairST *tmp_ptr = NULL;

    if (NULL == data_blocks_array_ptr) {
        return 0;
    }

    previous_row_prefix_sum_array_ptr = data_blocks_array_ptr;
    current_row_prefix_sum_array_ptr = (
        data_blocks_array_ptr + (GRID_MATRIX_COLUMNS_NUMBER + 1)
    );

    for (int row_index = 0; row_index < GRID_MATRIX_ROWS_NUMBER; ++row_index) {
        for (
            int column_index = 0;
            column_index < GRID_MATRIX_COLUMNS_NUMBER;
            ++column_index
        ) {
            total_x_characters_count = (
                ((previous_row_prefix_sum_array_ptr[column_index + 1]).x_characters_count)
                +
                ((current_row_prefix_sum_array_ptr[column_index]).x_characters_count)
                -
                ((previous_row_prefix_sum_array_ptr[column_index]).x_characters_count)
            );
            total_y_characters_count = (
                ((previous_row_prefix_sum_array_ptr[column_index + 1]).y_characters_count)
                +
                ((current_row_prefix_sum_array_ptr[column_index]).y_characters_count)
                -
                ((previous_row_prefix_sum_array_ptr[column_index]).y_characters_count)
            );

            if ('X' == (grid[row_index][column_index])) {
                ++total_x_characters_count;
            }
            else if ('Y' == (grid[row_index][column_index])) {
                ++total_y_characters_count;
            }

            if (
                (total_x_characters_count > 0)
                &&
                (total_x_characters_count == total_y_characters_count)
            ) {
                ++valid_submatrices_count;
            }

            (current_row_prefix_sum_array_ptr[column_index + 1]).x_characters_count = (
                total_x_characters_count
            );
            (current_row_prefix_sum_array_ptr[column_index + 1]).y_characters_count = (
                total_y_characters_count
            );
        }

        tmp_ptr = previous_row_prefix_sum_array_ptr;
        previous_row_prefix_sum_array_ptr = current_row_prefix_sum_array_ptr;
        current_row_prefix_sum_array_ptr = tmp_ptr;
    }

    free(data_blocks_array_ptr);
    data_blocks_array_ptr = NULL;
    previous_row_prefix_sum_array_ptr = NULL;
    current_row_prefix_sum_array_ptr = NULL;

    return valid_submatrices_count;
}
