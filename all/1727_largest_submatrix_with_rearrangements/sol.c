#include <stdlib.h>

static inline int max(const int i1, const int i2) {
    return ((i1 > i2) ? i1 : i2);
}

static inline int min(const int i1, const int i2) {
    return ((i1 < i2) ? i1 : i2);
}

static int compareFunction(const void *p1, const void *p2) {
    const int i1 = (*((const int*)p1));
    const int i2 = (*((const int*)p2));

    return ((i1 < i2) - (i1 > i2));
}

int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize) {
    if (0 == matrixSize) {
        return 0;
    }

    const int MATRIX_ROWS_NUMBER = matrixSize;
    const int MATRIX_COLUMNS_NUMBER = matrixColSize[0];

    int largest_area = 0;

    /* Count how many consecutive ones at each position in a column. */
    for (int row_index = 1; row_index < MATRIX_ROWS_NUMBER; ++row_index) {
        for (
            int column_index = 0;
            column_index < MATRIX_COLUMNS_NUMBER;
            ++column_index
        ) {
            if (matrix[row_index][column_index]) {
                matrix[row_index][column_index] += (
                    matrix[row_index - 1][column_index]
                );
            }
        }
    }

    for (int row_index = 0; row_index < MATRIX_ROWS_NUMBER; ++row_index) {
        /* Sort the consecutive ones count in each row in decreasing order. */
        qsort(
            matrix[row_index],
            MATRIX_COLUMNS_NUMBER,
            sizeof(*(matrix[row_index])),
            &compareFunction
        );

        /*
         * Try every possible rectangles that be formed by using current row
         * as the bottom border.
         *
         * Length of the bottom border will continue to expand until we
         * encounter a 0, which means the height of rectangle will be 0.
         */
        for (
            int column_index = 0;
            column_index < MATRIX_COLUMNS_NUMBER;
            ++column_index
        ) {
            if (0 == (matrix[row_index][column_index])) {
                break;
            }

            largest_area = max(
                largest_area,
                (matrix[row_index][column_index]) * (column_index + 1)
            );
        }
    }

    return largest_area;
}
