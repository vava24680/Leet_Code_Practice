#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static void swapTwoIntegers(int * const p1, int * const p2) {
    if (p1 == p2) {
        return;
    }

    int tmp = (*p1);
    (*p1) = (*p2);
    (*p2) = tmp;
}

int** reverseSubmatrix(
    int** grid,
    int gridSize,
    int* gridColSize,
    int x,
    int y,
    int k,
    int* returnSize,
    int** returnColumnSizes
) {
    (*returnSize) = 0;
    (*returnColumnSizes) = NULL;

    if (0 == gridSize) {
        return NULL;
    }

    const int GRID_MATRIX_ROWS_NUMBER = gridSize;
    const int GRID_MATRIX_COLUMNS_NUMBER = (gridColSize[0]);

    int **answer_matrix_ptr = (
        (int**)malloc(
            sizeof(*answer_matrix_ptr) * GRID_MATRIX_ROWS_NUMBER
        )
    );
    int row_index_1 = 0;
    int row_index_2 = 0;

    (*returnColumnSizes) = (
        (int*)malloc(sizeof(**returnColumnSizes) * GRID_MATRIX_ROWS_NUMBER)
    );

    if ((NULL == answer_matrix_ptr) || (NULL == (*returnColumnSizes))) {
        free(answer_matrix_ptr);
        free(*returnColumnSizes);

        return NULL;
    }

    for (int row_index = 0; row_index < GRID_MATRIX_ROWS_NUMBER; ++row_index) {
        answer_matrix_ptr[row_index] = (
            (int*)malloc(
                sizeof(*(answer_matrix_ptr[row_index]))
                *
                GRID_MATRIX_COLUMNS_NUMBER
            )
        );

        if (NULL == (answer_matrix_ptr[row_index])) {
            for (int j = 0; j < row_index; ++j) {
                free(answer_matrix_ptr[j]);
                answer_matrix_ptr[j] = NULL;
            }

            free(*returnColumnSizes);
            (*returnColumnSizes) = NULL;

            free(answer_matrix_ptr);
            answer_matrix_ptr = NULL;

            return NULL;
        }

        ((*returnColumnSizes)[row_index]) = GRID_MATRIX_COLUMNS_NUMBER;

        /* Copy the corresponding row to the new matrix. */
        memcpy(
            answer_matrix_ptr[row_index],
            grid[row_index],
            sizeof(*(grid[row_index])) * GRID_MATRIX_COLUMNS_NUMBER
        );
    }

    for (int i = 0; i < (k >> 1); ++i) {
        /*
         * Use two pointers to point the two rows that should be reversed
         * vertically.
         */
        row_index_1 = (x + i);
        row_index_2 = (x + (k - 1 - i));

        for (int column_index = y; column_index < (y + k); ++column_index) {
            swapTwoIntegers(
                &(answer_matrix_ptr[row_index_1][column_index]),
                &(answer_matrix_ptr[row_index_2][column_index])
            );
        }
    }

    (*returnSize) = GRID_MATRIX_ROWS_NUMBER;

    return answer_matrix_ptr;
}
