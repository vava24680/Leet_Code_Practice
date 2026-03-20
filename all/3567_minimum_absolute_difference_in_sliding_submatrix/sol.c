#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

int llmin(const long long ll1, const long long ll2) {
    return ((ll1 < ll2) ? ll1 : ll2);
}

int compareFunction(const void *p1, const void *p2) {
    const int i1 = (*((const int*)p1));
    const int i2 = (*((const int*)p2));

    return ((i1 > i2) - (i1 < i2));
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** minAbsDiff(
    int** grid,
    int gridSize,
    int* gridColSize,
    int k,
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

    int **answer_matrix_ptr = (int**)malloc(
        sizeof(*answer_matrix_ptr) * (GRID_MATRIX_ROWS_NUMBER - k + 1)
    );
    int *sorting_array_ptr = (int*)malloc(sizeof(*sorting_array_ptr) * k * k);
    (*returnColumnSizes) = (
        (int*)malloc(
            sizeof(**returnColumnSizes) * (GRID_MATRIX_ROWS_NUMBER - k + 1)
        )
    );
    int next_write_index = 0;
    long long minimum_absolute_difference = LLONG_MAX;

    for (
        int row_index = 0;
        row_index < (GRID_MATRIX_ROWS_NUMBER - k + 1);
        ++row_index
    ) {
        answer_matrix_ptr[row_index] = (int*)malloc(
            sizeof(*(answer_matrix_ptr[row_index]))
            *
            (GRID_MATRIX_COLUMNS_NUMBER - k + 1)
        );
        ((*returnColumnSizes)[row_index]) = (GRID_MATRIX_COLUMNS_NUMBER - k + 1);
    }

    for (
        int top_left_row_index = 0;
        top_left_row_index < (GRID_MATRIX_ROWS_NUMBER - k + 1);
        ++top_left_row_index
    ) {
        for (
            int top_left_column_index = 0;
            top_left_column_index < (GRID_MATRIX_COLUMNS_NUMBER - k + 1);
            ++top_left_column_index
        ) {
            next_write_index = 0;
            minimum_absolute_difference = LLONG_MAX;

            for (
                int row_index = top_left_row_index;
                row_index < (top_left_row_index + k);
                ++row_index
            ) {
                for (
                    int column_index = top_left_column_index;
                    column_index < (top_left_column_index + k);
                    ++column_index
                ) {
                    sorting_array_ptr[next_write_index] = (
                        grid[row_index][column_index]
                    );
                    ++next_write_index;
                }
            }

            qsort(
                sorting_array_ptr,
                k * k,
                sizeof(*sorting_array_ptr),
                &compareFunction
            );

            for (int i = 1; i < (k * k); ++i) {
                if ((sorting_array_ptr[i]) == (sorting_array_ptr[i - 1])) {
                    continue;
                }

                minimum_absolute_difference = llmin(
                    minimum_absolute_difference,
                    (long long)(
                        (sorting_array_ptr[i]) - (sorting_array_ptr[i - 1])
                    )
                );
            }

            if (LLONG_MAX == minimum_absolute_difference) {
                minimum_absolute_difference = 0;
            }

            answer_matrix_ptr[top_left_row_index][top_left_column_index] = (
                (int)minimum_absolute_difference
            );
        }
    }

    free(sorting_array_ptr);
    sorting_array_ptr = NULL;

    (*returnSize) = (GRID_MATRIX_ROWS_NUMBER - k + 1);

    return answer_matrix_ptr;
}
