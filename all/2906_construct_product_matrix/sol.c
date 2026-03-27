#include <stddef.h>
#include <stdlib.h>

const long long MODULO_LL = 12345LL;

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** constructProductMatrix(
    int** grid,
    int gridSize,
    int* gridColSize,
    int* returnSize,
    int** returnColumnSizes
) {
    if (0 == gridSize) {
        (*returnSize) = 0;
        (*returnColumnSizes) = NULL;

        return NULL;
    }

    const int GRID_MATRIX_ROWS_NUMBER = gridSize;
    const int GRID_MATRIX_COLUMNS_NUMBER = (gridColSize[0]);

    long long previous_prefix_product = 1;
    long long previous_suffix_product = 1;

    int **answer_matrix_ptr = (
        (int**)malloc(sizeof(*answer_matrix_ptr) * GRID_MATRIX_ROWS_NUMBER)
    );
    (*returnColumnSizes) = (
        (int*)malloc(sizeof(**returnColumnSizes) * GRID_MATRIX_ROWS_NUMBER)
    );

    for (int row_index = 0; row_index < GRID_MATRIX_ROWS_NUMBER; ++row_index) {
        answer_matrix_ptr[row_index] = (
            (int*)malloc(
                sizeof(*(answer_matrix_ptr[row_index]))
                *
                GRID_MATRIX_COLUMNS_NUMBER
            )
        );
        (*returnColumnSizes)[row_index] = GRID_MATRIX_COLUMNS_NUMBER;
    }

    for (int row_index = 0; row_index < GRID_MATRIX_ROWS_NUMBER; ++row_index) {
        for (
            int column_index = 0;
            column_index < GRID_MATRIX_COLUMNS_NUMBER;
            ++column_index
        ) {
            answer_matrix_ptr[row_index][column_index] = (
                (int)previous_prefix_product
            );
            /* Update previous prefix product. */
            previous_prefix_product = (
                (
                    previous_prefix_product
                    *
                    ((long long)(grid[row_index][column_index]))
                )
                %
                MODULO_LL
            );
        }
    }

    for (
        int row_index = (GRID_MATRIX_ROWS_NUMBER - 1);
        row_index >= 0;
        --row_index
    ) {
        for (
            int column_index = (GRID_MATRIX_COLUMNS_NUMBER - 1);
            column_index >= 0;
            --column_index
        ) {
            answer_matrix_ptr[row_index][column_index] = (
                (
                    ((long long)(answer_matrix_ptr[row_index][column_index]))
                    *
                    previous_suffix_product
                )
                %
                MODULO_LL
            );
            /* Update previous suffix product. */
            previous_suffix_product = (
                (
                    (long long)(grid[row_index][column_index])
                    *
                    previous_suffix_product
                )
                %
                MODULO_LL
            );
        }
    }

    (*returnSize) = GRID_MATRIX_ROWS_NUMBER;

    return answer_matrix_ptr;
}
