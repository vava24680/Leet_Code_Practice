#include <stdlib.h>

int numSpecial(int** mat, int matSize, int* matColSize) {
    int special_positions_count = 0;
    int *ones_count_array_ptr = (
        (int*)calloc(matSize + matColSize[0], sizeof(*ones_count_array_ptr))
    );
    int *per_row_ones_count_array_ptr = ones_count_array_ptr;
    int *per_column_ones_count_array_ptr = ones_count_array_ptr + matSize;

    /* Count how many 0 in each row and each column. */
    for (int row_index = 0; row_index < matSize; ++row_index) {
        for (
            int column_index = 0;
            column_index < (matColSize[0]);
            ++column_index
        ) {
            if (0 == mat[row_index][column_index]) {
                continue;
            }

            ++(per_row_ones_count_array_ptr[row_index]);
            ++(per_column_ones_count_array_ptr[column_index]);
        }
    }

    /* Count how many positions are special in the given binary matrix. */
    for (int row_index = 0; row_index < matSize; ++row_index) {
        for (
            int column_index = 0;
            column_index < (matColSize[0]);
            ++column_index
        ) {
            if (0 == mat[row_index][column_index]) {
                continue;
            }

            if (
                (1 == per_row_ones_count_array_ptr[row_index])
                &&
                (1 == per_column_ones_count_array_ptr[column_index])
            ) {
                ++special_positions_count;
            }
        }
    }

    free(ones_count_array_ptr);
    per_row_ones_count_array_ptr = NULL;
    per_column_ones_count_array_ptr = NULL;
    ones_count_array_ptr = NULL;

    return special_positions_count;
}
