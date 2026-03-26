from typing import List


class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        if not grid:
            return False

        GRID_MATRIX_ROWS_NUMBER = len(grid)
        GRID_MATRIX_COLUMNS_NUMBER = len(grid[0])

        prefix_sum_matrix = [
            [0] * (GRID_MATRIX_COLUMNS_NUMBER + 1)
            for _ in range(GRID_MATRIX_ROWS_NUMBER + 1)
        ]

        for row_index, row in enumerate(grid):
            for column_index, current_cell_value in enumerate(row):
                prefix_sum_matrix[row_index + 1][column_index + 1] = (
                    current_cell_value
                    +
                    prefix_sum_matrix[row_index + 1][column_index]
                    +
                    prefix_sum_matrix[row_index][column_index + 1]
                    -
                    prefix_sum_matrix[row_index][column_index]
                )

        if (
            (
                prefix_sum_matrix[
                    GRID_MATRIX_ROWS_NUMBER
                ][
                    GRID_MATRIX_COLUMNS_NUMBER
                ]
            )
            &
            0x1
        ):
            # If total sum is an odd number, it is impossible that we can cut
            # the matrix into two parts with equal sum.
            return False

        for row_index in range(GRID_MATRIX_ROWS_NUMBER - 1):
            if (
                (prefix_sum_matrix[row_index + 1][GRID_MATRIX_COLUMNS_NUMBER])
                ==
                (
                    (
                        prefix_sum_matrix[
                            GRID_MATRIX_ROWS_NUMBER
                        ][
                            GRID_MATRIX_COLUMNS_NUMBER
                        ]
                    )
                    -
                    (
                        prefix_sum_matrix[
                            row_index + 1
                        ][
                            GRID_MATRIX_COLUMNS_NUMBER
                        ]
                    )
                )
            ):
                return True

        for column_index in range(GRID_MATRIX_COLUMNS_NUMBER - 1):
            if (
                (prefix_sum_matrix[GRID_MATRIX_ROWS_NUMBER][column_index + 1])
                ==
                (
                    (
                        prefix_sum_matrix[
                            GRID_MATRIX_ROWS_NUMBER
                        ][
                            GRID_MATRIX_COLUMNS_NUMBER
                        ]
                    )
                    -
                    (
                        prefix_sum_matrix[
                            GRID_MATRIX_ROWS_NUMBER
                        ][
                            column_index + 1
                        ]
                    )
                )
            ):
                return True

        return False


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[[1, 4], [2, 3]]],
        [[[1, 3], [2, 4]]],
    ]

    for testcase in testcases_list:
        print(sol.canPartitionGrid(*testcase))
