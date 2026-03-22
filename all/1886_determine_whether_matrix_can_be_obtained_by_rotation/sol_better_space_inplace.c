#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

static void swapTwoIntegers(int *p1, int *p2) {
    if (p1 == p2) {
        return;
    }

    int tmp = (*p1);
    (*p1) = (*p2);
    (*p2) = tmp;
}

static bool areTwoMatrixTheSame(
    int **matrix_1_ptr,
    int **matrix_2_ptr,
    const int matrix_rows_number,
    const int matrix_columns_number
) {
    for (int row_index = 0; row_index < matrix_rows_number; ++row_index) {
        for (
            int column_index = 0;
            column_index < matrix_columns_number;
            ++column_index
        ) {
            if (
                (matrix_1_ptr[row_index][column_index])
                !=
                (matrix_2_ptr[row_index][column_index])
            ) {
                return false;
            }
        }
    }
    return true;
}

bool findRotation(
    int** matrix,
    int matrixSize,
    int* matrixColSize,
    int** targetMatrix,
    int targetSize,
    int* targetColSize
) {
    const int MATRIX_ROWS_NUMBER = matrixSize;
    const int MATRIX_COLUMNS_NUMBER = (matrixColSize[0]);

    if (
        areTwoMatrixTheSame(
            matrix,
            targetMatrix,
            MATRIX_ROWS_NUMBER,
            MATRIX_COLUMNS_NUMBER
        )
    ) {
        return true;
    }

    for (int rotation_times = 0; rotation_times < 3; ++rotation_times) {
        /*
         * Transpose the matrix and the reverse each row in the matrix have
         * same effect as rotating the matrix 90 degrees clockwise.
         */
        /* Transpose the matrix. */
        for (int row_index = 0; row_index < MATRIX_ROWS_NUMBER; ++row_index) {
            for (
                int column_index = (row_index + 1);
                column_index < MATRIX_COLUMNS_NUMBER;
                ++column_index
            ) {
                swapTwoIntegers(
                    &(matrix[row_index][column_index]),
                    &(matrix[column_index][row_index])
                );
            }
        }

        /* Reverse each row in the matrix. */
        for (int row_index = 0; row_index < MATRIX_ROWS_NUMBER; ++row_index) {
            for (
                int column_index = 0;
                column_index < (MATRIX_COLUMNS_NUMBER >> 1);
                ++column_index
            ) {
                swapTwoIntegers(
                    &(matrix[row_index][column_index]),
                    &(matrix[row_index][MATRIX_COLUMNS_NUMBER - 1 - column_index])
                );
            }
        }

        if (
            areTwoMatrixTheSame(
                matrix,
                targetMatrix,
                MATRIX_ROWS_NUMBER,
                MATRIX_COLUMNS_NUMBER
            )
        ) {
            return true;
        }
    }

    return false;
}
