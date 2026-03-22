#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(
    int** matrix,
    int matrixSize,
    int* matrixColSize,
    int* returnSize,
    int** returnColumnSizes
) {
    const int MATRIX_ROWS_NUMBER = matrixSize;
    const int MATRIX_COLUMNS_NUMBER = matrixColSize[0];

    int **result_matrix = (
        (int**)malloc(sizeof(*matrix) * MATRIX_COLUMNS_NUMBER)
    );
    (*returnColumnSizes) = (int*)malloc(
        sizeof(**returnColumnSizes) * MATRIX_COLUMNS_NUMBER
    );

    for (int i = 0; i < MATRIX_COLUMNS_NUMBER; ++i) {
        result_matrix[i] = (
            (int*)malloc(sizeof(**result_matrix) * MATRIX_ROWS_NUMBER)
        );
        (*returnColumnSizes)[i] = MATRIX_ROWS_NUMBER;
    }

    for (int row_index = 0; row_index < MATRIX_ROWS_NUMBER; ++row_index) {
        for (
            int column_index = 0;
            column_index < MATRIX_COLUMNS_NUMBER;
            ++column_index
        ) {
            result_matrix[column_index][row_index] = (
                matrix[row_index][column_index]
            );
        }
    }

    (*returnSize) = MATRIX_COLUMNS_NUMBER;

    return result_matrix;
}
