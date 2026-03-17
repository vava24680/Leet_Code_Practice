#include <stdlib.h>

typedef struct {
    int height;
    int column_index;
} HeightAndColumnIndexTupleST;

static inline int max(const int i1, const int i2) {
    return ((i1 > i2) ? i1 : i2);
}

int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize) {
    if (0 == matrixSize) {
        return 0;
    }

    const int MATRIX_ROWS_NUMBER = matrixSize;
    const int MATRIX_COLUMNS_NUMBER = matrixColSize[0];

    int largest_area = 0;
    HeightAndColumnIndexTupleST *data_blocks_array_ptr = (
        (HeightAndColumnIndexTupleST*)malloc(
            sizeof(*data_blocks_array_ptr) * MATRIX_COLUMNS_NUMBER * 2
        )
    );
    HeightAndColumnIndexTupleST *previous_row_sorted_heights_array_ptr = NULL;
    HeightAndColumnIndexTupleST *current_row_sorted_heights_array_ptr = NULL;
    HeightAndColumnIndexTupleST *tmp_ptr = NULL;

    if (NULL == data_blocks_array_ptr) {
        return 0;
    }

    previous_row_sorted_heights_array_ptr = data_blocks_array_ptr;
    current_row_sorted_heights_array_ptr = (
        data_blocks_array_ptr + MATRIX_COLUMNS_NUMBER
    );

    for (
        int column_index = 0;
        column_index < MATRIX_COLUMNS_NUMBER;
        ++column_index
    ) {
        previous_row_sorted_heights_array_ptr[column_index].height = 0;
        previous_row_sorted_heights_array_ptr[column_index].column_index = (
            column_index
        );
    }

    for (int row_index = 0; row_index < MATRIX_ROWS_NUMBER; ++row_index) {
        /*
         * Use the sorted heights result in the previous row to construct
         * the sorted heights result in the current row.
         * Check notes for the detailed sorting logic.
         */
        int next_available_index_from_front = 0;
        int next_available_index_from_rear = (MATRIX_COLUMNS_NUMBER - 1);

        for (
            int i = 0, current_processed_column_index = 0;
            i < MATRIX_COLUMNS_NUMBER;
            ++i
        ) {
            current_processed_column_index = (
                previous_row_sorted_heights_array_ptr[i].column_index
            );

            if (matrix[row_index][current_processed_column_index]) {
                /* A column has at least height 1 in the current row. */
                current_row_sorted_heights_array_ptr[
                    next_available_index_from_front
                ].height = (
                    previous_row_sorted_heights_array_ptr[i].height + 1
                );
                current_row_sorted_heights_array_ptr[
                    next_available_index_from_front
                ].column_index = current_processed_column_index;

                ++next_available_index_from_front;
            }
            else {
                /* A column has does not have height in the current row. */
                current_row_sorted_heights_array_ptr[
                    next_available_index_from_rear
                ].height = 0; current_row_sorted_heights_array_ptr[
                    next_available_index_from_rear
                ].column_index = current_processed_column_index;

                --next_available_index_from_rear;
            }
        }

        /*
         * Try every possible rectangles that be formed by using current row
         * as the bottom border.
         *
         * Length of the bottom border will continue to expand until we
         * encounter a 0, which means the height of rectangle will be 0.
         */
        for (int i = 0; i < MATRIX_COLUMNS_NUMBER; ++i) {
            if (0 == (current_row_sorted_heights_array_ptr[i].height)) {
                break;
            }

            largest_area = max(
                largest_area,
                (current_row_sorted_heights_array_ptr[i].height) * (i + 1)
            );
        }

        tmp_ptr = current_row_sorted_heights_array_ptr;
        current_row_sorted_heights_array_ptr = (
            previous_row_sorted_heights_array_ptr
        );
        previous_row_sorted_heights_array_ptr = tmp_ptr;
    }

    free(data_blocks_array_ptr);
    data_blocks_array_ptr = NULL;
    previous_row_sorted_heights_array_ptr = NULL;
    current_row_sorted_heights_array_ptr = NULL;

    return largest_area;
}
