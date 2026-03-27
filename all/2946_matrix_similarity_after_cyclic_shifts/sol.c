#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

bool areSimilar(int** matrix, int matSize, int* matColSize, int k) {
    if (0 == matSize) {
        return true;
    }

    const int MATRIX_ROWS_NUMBER = matSize;
    const int MATRIX_COLUMNS_NUMBER = (matColSize[0]);

    bool result = true;
    int **modified_matrix_ptr = (
        (int**)malloc(sizeof(*modified_matrix_ptr) * MATRIX_ROWS_NUMBER)
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
    int new_column_index = 0;

    if ((NULL == modified_matrix_ptr) || (NULL == data_blocks_array_ptr)) {
        free(modified_matrix_ptr);
        modified_matrix_ptr = NULL;

        free(data_blocks_array_ptr);
        data_blocks_array_ptr = NULL;

        return false;
    }

    for (int row_index = 0; row_index < MATRIX_ROWS_NUMBER; ++row_index) {
        modified_matrix_ptr[row_index] = (
            data_blocks_array_ptr + (row_index * MATRIX_COLUMNS_NUMBER)
        );
    }

    for (
        int column_index = 0;
        column_index < MATRIX_COLUMNS_NUMBER;
        ++column_index
    ) {
        /* Adjust even rows. */
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
            modified_matrix_ptr[row_index][new_column_index] = (
                matrix[row_index][column_index]
            );
        }

        /* Adjust odd rows. */
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
            modified_matrix_ptr[row_index][new_column_index] = (
                matrix[row_index][column_index]
            );
        }
    }

    /* Check if the modified matrix is as same as the original matrix. */
    for (int row_index = 0; row_index < MATRIX_ROWS_NUMBER; ++row_index) {
        for (
            int column_index = 0;
            column_index < MATRIX_COLUMNS_NUMBER;
            ++column_index
        ) {
            if (
                (modified_matrix_ptr[row_index][column_index])
                !=
                (matrix[row_index][column_index])
            ) {
                result = false;

                goto FINAL_CLEANUP;
            }
        }
    }

FINAL_CLEANUP:
    free(modified_matrix_ptr);
    modified_matrix_ptr = NULL;

    free(data_blocks_array_ptr);
    data_blocks_array_ptr = NULL;

    return result;
}
