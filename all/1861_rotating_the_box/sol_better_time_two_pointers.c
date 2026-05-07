#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char** rotateTheBox(
    char** boxGrid,
    int boxGridSize,
    int* boxGridColSize,
    int* returnSize,
    int** returnColumnSizes
) {
    const int ORIGINAL_MATRIX_ROWS_NUMBER = boxGridSize;
    const int ORIGINAL_MATRIX_COLUMNS_NUMBER = (boxGridColSize[0]);
    const int NEW_MATRIX_ROWS_NUMBER = ORIGINAL_MATRIX_COLUMNS_NUMBER;
    const int NEW_MATRIX_COLUMNS_NUMBER = ORIGINAL_MATRIX_ROWS_NUMBER;

    int new_row_index = 0, new_column_index = 0;
    int rightmost_available_column_index = 0;
    char **answer_matrix_ptr = (char**)malloc(
        sizeof(*answer_matrix_ptr) * NEW_MATRIX_ROWS_NUMBER
    );
    (*returnColumnSizes) = (int*)malloc(
        sizeof(**returnColumnSizes) * NEW_MATRIX_ROWS_NUMBER
    );

    for (
        int row_index = 0;
        row_index < NEW_MATRIX_ROWS_NUMBER;
        ++row_index
    ) {
        answer_matrix_ptr[row_index] = (
            (char*)malloc(
                sizeof(*(answer_matrix_ptr[row_index]))
                *
                NEW_MATRIX_COLUMNS_NUMBER
            )
        );
        /* Initialize all cells in the answer matrix to '*'. */
        memset(
            (void*)(answer_matrix_ptr[row_index]),
            '.',
            NEW_MATRIX_COLUMNS_NUMBER
        );
        (*returnColumnSizes)[row_index] = NEW_MATRIX_COLUMNS_NUMBER;
    }

    for (
        int row_index = 0;
        row_index < ORIGINAL_MATRIX_ROWS_NUMBER;
        ++row_index
    ) {
        rightmost_available_column_index = (ORIGINAL_MATRIX_COLUMNS_NUMBER - 1);

        for (
            int column_index = (ORIGINAL_MATRIX_COLUMNS_NUMBER - 1);
            column_index >= 0;
            --column_index
        ) {
            if ('#' == (boxGrid[row_index][column_index])) {
                /*
                 * Compute the row index and the column index of the location
                 * where current stone will fall down.
                 */
                new_row_index = rightmost_available_column_index;
                new_column_index = (
                    ORIGINAL_MATRIX_ROWS_NUMBER - 1 - row_index
                );
                answer_matrix_ptr[new_row_index][new_column_index] = '#';

                --rightmost_available_column_index;
            }
            else if ('*' == (boxGrid[row_index][column_index])) {
                /*
                 * If content in the current cell is an obstacle, it will not
                 * fall after rotation.
                 */
                new_row_index = column_index;
                new_column_index = (
                    ORIGINAL_MATRIX_ROWS_NUMBER - 1 - row_index
                );
                answer_matrix_ptr[new_row_index][new_column_index] = (
                    boxGrid[row_index][column_index]
                );

                /*
                 * Update rightmost available column index for a stone
                 * since current cell is a stone.
                 */
                rightmost_available_column_index = (column_index - 1);
            }
        }
    }

    (*returnSize) = NEW_MATRIX_ROWS_NUMBER;

    return answer_matrix_ptr;
}
