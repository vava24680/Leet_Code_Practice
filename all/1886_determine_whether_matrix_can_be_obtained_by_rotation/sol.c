#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

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

    int **rotated_matrix_ptr = (
        (int**)malloc(sizeof(*rotated_matrix_ptr) * MATRIX_ROWS_NUMBER)
    );
    int *data_blocks_array_ptr = (
        (int*)malloc(
            sizeof(*data_blocks_array_ptr)
            *
            MATRIX_ROWS_NUMBER
            *
            MATRIX_COLUMNS_NUMBER
        )
    );
    int **tmp_ptr = NULL, **backed_rotated_matrix_ptr = NULL;
    bool result = false;

    if ((NULL == rotated_matrix_ptr) || (NULL == data_blocks_array_ptr)) {
        free(rotated_matrix_ptr);
        rotated_matrix_ptr = NULL;

        free(data_blocks_array_ptr);
        data_blocks_array_ptr = NULL;

        return false;
    }

    backed_rotated_matrix_ptr = rotated_matrix_ptr;

    for (int row_index = 0; row_index < MATRIX_ROWS_NUMBER; ++row_index) {
        rotated_matrix_ptr[row_index] = (
            data_blocks_array_ptr + (row_index * MATRIX_COLUMNS_NUMBER)
        );
    }

    /*
     * Swap the matrices pointed by the original matrix pointer and the rotated
     * matrix pointer.
     */
    tmp_ptr = rotated_matrix_ptr;
    rotated_matrix_ptr = matrix;
    matrix = tmp_ptr;

    for (int rotation_times = 0; rotation_times < 4; ++rotation_times) {
        if (
            areTwoMatrixTheSame(
                rotated_matrix_ptr,
                targetMatrix,
                MATRIX_ROWS_NUMBER,
                MATRIX_COLUMNS_NUMBER
            )
        ) {
            result = true;

            break;
        }

        /*
         * Swap the matrices pointed by the original matrix pointer and the rotated
         * matrix pointer.
         */
        tmp_ptr = matrix;
        matrix = rotated_matrix_ptr;
        rotated_matrix_ptr = tmp_ptr;

        for (int row_index = 0; row_index < MATRIX_ROWS_NUMBER; ++row_index) {
            for (
                int column_index = 0;
                column_index < MATRIX_COLUMNS_NUMBER;
                ++column_index
            ) {
                rotated_matrix_ptr[
                    column_index
                ][
                    MATRIX_ROWS_NUMBER - 1 - row_index
                ] = (matrix[row_index][column_index]);
            }
        }
    }

    if (rotated_matrix_ptr != backed_rotated_matrix_ptr) {
        /*
         * If the matrix that rotated matrix pointer points to is not the
         * original allocated one, we need to swap it with the originam matrix
         * pointer, so the following memcoy deallocation will not fail.
         */
        tmp_ptr = matrix;
        matrix = rotated_matrix_ptr;
        rotated_matrix_ptr = tmp_ptr;
    }

    free(rotated_matrix_ptr);
    rotated_matrix_ptr = NULL;

    free(data_blocks_array_ptr);
    data_blocks_array_ptr = NULL;

    return result;
}
