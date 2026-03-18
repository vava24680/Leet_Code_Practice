int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {
    if ((0 == gridSize) || (grid[0][0] > k)) {
        return 0;
    }

    const int GRID_MATRIX_ROWS_NUMBER = gridSize;
    const int GRID_MATRIX_COLUMNS_NUMBER = gridColSize[0];

    int valid_submatrices_count = 1;

    for (
        int column_index = 1;
        column_index < GRID_MATRIX_COLUMNS_NUMBER;
        ++column_index
    ) {
        grid[0][column_index] += (grid[0][column_index - 1]);

        if (grid[0][column_index] <= k) {
            ++valid_submatrices_count;
        }
    }

    for (int row_index = 1; row_index < GRID_MATRIX_ROWS_NUMBER; ++row_index) {
        grid[row_index][0] += (grid[row_index - 1][0]);

        if (grid[row_index][0] <= k) {
            ++valid_submatrices_count;
        }
    }

    for (int row_index = 1; row_index < GRID_MATRIX_ROWS_NUMBER; ++row_index) {
        for (
            int column_index = 1;
            column_index < GRID_MATRIX_COLUMNS_NUMBER;
            ++column_index
        ) {
            grid[row_index][column_index] += (
                grid[row_index - 1][column_index]
                +
                grid[row_index][column_index - 1]
                -
                grid[row_index - 1][column_index - 1]
            );

            if (grid[row_index][column_index] <= k) {
                ++valid_submatrices_count;
            }
        }
    }

    return valid_submatrices_count;
}
