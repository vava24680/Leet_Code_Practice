static void swapTwoIntegers(int *int_1_ptr, int *int_2_ptr) {
    if (
        (NULL == int_1_ptr)
        ||
        (NULL == int_2_ptr)
        ||
        (int_1_ptr == int_2_ptr)
    ) {
        return;
    }

    int tmp = (*int_1_ptr);
    (*int_1_ptr) = (*int_2_ptr);
    (*int_2_ptr) = tmp;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    const int MATRIX_ROWS_NUMBER = matrixSize;
    const int MATRIX_COLUMNS_NUMBER = (matrixColSize[0]);

    /* Transpose the given matrix. */
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

    /* Reverse each row in the given matrix. */
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
}
