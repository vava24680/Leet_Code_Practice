#include <stdlib.h>

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
        answer_matrix_ptr[row_index] = (char*)malloc(
            sizeof(*(answer_matrix_ptr[row_index]))
            *
            NEW_MATRIX_COLUMNS_NUMBER
        );
        (*returnColumnSizes)[row_index] = NEW_MATRIX_COLUMNS_NUMBER;
    }

    for (
        int original_column_index = (ORIGINAL_MATRIX_COLUMNS_NUMBER - 1);
        original_column_index >= 0;
        --original_column_index
    ) {
        new_row_index = original_column_index;

        /* Rotate a column in the boxGrid clockwise 90 degrees. */
        for (
            int original_row_index = 0;
            original_row_index < ORIGINAL_MATRIX_ROWS_NUMBER;
            ++original_row_index
        ) {
            new_column_index = (
                ORIGINAL_MATRIX_ROWS_NUMBER - 1 - original_row_index
            );

            answer_matrix_ptr[new_row_index][new_column_index] = (
                boxGrid[original_row_index][original_column_index]
            );
        }

        /*
         * A column becomes a row after rotating clockwise 90 degrees.
         * Iterate all cells in that row.
         */
        for (
            int new_column_index = 0, current_row_index;
            new_column_index < NEW_MATRIX_COLUMNS_NUMBER;
            ++new_column_index
        ) {
            current_row_index = new_row_index;

            if (
                ('*' == (answer_matrix_ptr[new_row_index][new_column_index]))
                ||
                ('.' == (answer_matrix_ptr[new_row_index][new_column_index]))
            ) {
                /* Skip cells that are not stone. */
                continue;
            }

            /*
             * Make stone fall one cell down until it reaches bottom
             * or an obstacle.
             */
            while (
                ((current_row_index + 1) < NEW_MATRIX_ROWS_NUMBER)
                &&
                (
                    '.'
                    ==
                    (answer_matrix_ptr[current_row_index + 1][new_column_index])
                )
            ) {
                answer_matrix_ptr[current_row_index][new_column_index] = '.';
                answer_matrix_ptr[current_row_index + 1][new_column_index] = (
                    '#'
                );

                ++current_row_index;
            }
        }
    }

    (*returnSize) = NEW_MATRIX_ROWS_NUMBER;

    return answer_matrix_ptr;
}
