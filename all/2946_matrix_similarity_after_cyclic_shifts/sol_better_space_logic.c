#include <stdbool.h>

bool areSimilar(int** matrix, int matSize, int* matColSize, int k) {
    if (0 == matSize) {
        return true;
    }

    const int MATRIX_ROWS_NUMBER = matSize;
    const int MATRIX_COLUMNS_NUMBER = (matColSize[0]);

    int new_column_index = 0;

    /*
     * Compute the actual left/right shift times.
     * Because left/right shift MATRIX_COLUMNS_NUMBER times will wrap around
     * to the original position.
     */
    k %= MATRIX_COLUMNS_NUMBER;

    if (0 == k) {
        /*
         * If actual left/shift times is 0, the modified matrix is definitely
         * as same as the original matrix.
         */
        return true;
    }

    /* Check even rows. */
    for (
        int column_index = 0;
        column_index < MATRIX_COLUMNS_NUMBER;
        ++column_index
    ) {
        new_column_index = (
            (
                ((column_index - k) % MATRIX_COLUMNS_NUMBER)
                +
                MATRIX_COLUMNS_NUMBER
            )
            %
            MATRIX_COLUMNS_NUMBER
        );

        for (
            int row_index = 0;
            row_index < MATRIX_ROWS_NUMBER;
            row_index += 2
        ) {
            if (
                (matrix[row_index][new_column_index])
                !=
                (matrix[row_index][column_index])
            ) {
                /*
                 * If the value in the original cell is different from the
                 * value in the new cell, it is impossible that modified
                 * matrix can be as same as the original matrix.
                 */
                return false;
            }
        }
    }

    for (
        int column_index = 0;
        column_index < MATRIX_COLUMNS_NUMBER;
        ++column_index
    ) {
        new_column_index = (
            (
                ((column_index + k) % MATRIX_COLUMNS_NUMBER)
                +
                MATRIX_COLUMNS_NUMBER
            )
            %
            MATRIX_COLUMNS_NUMBER
        );

        for (
            int row_index = 1;
            row_index < MATRIX_ROWS_NUMBER;
            row_index += 2
        ) {
            if (
                (matrix[row_index][new_column_index])
                !=
                (matrix[row_index][column_index])
            ) {
                /*
                 * If the value in the original cell is different from the
                 * value in the new cell, it is impossible that modified
                 * matrix can be as same as the original matrix.
                 */
                return false;
            }
        }
    }

    return true;
}
