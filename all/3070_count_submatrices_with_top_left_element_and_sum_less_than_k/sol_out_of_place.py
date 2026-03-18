from typing import List


class Solution:
    def countSubmatrices(self, grid: List[List[int]], k: int) -> int:
        if (not grid) or (grid[0][0] > k):
            return 0

        GRID_MATRIX_ROWS_NUMBER = len(grid)
        GRID_MATRIX_COLUMNS_NUMBER = len(grid[0])

        valid_submatrices_count = 0
        prefix_sum_matrix = [
            [0] * (GRID_MATRIX_COLUMNS_NUMBER + 1)
            for _ in range(GRID_MATRIX_ROWS_NUMBER + 1)
        ]

        for row_index in range(GRID_MATRIX_ROWS_NUMBER):
            for column_index in range(GRID_MATRIX_COLUMNS_NUMBER):
                prefix_sum_matrix[row_index + 1][column_index + 1] = (
                    prefix_sum_matrix[row_index][column_index + 1]
                    +
                    prefix_sum_matrix[row_index + 1][column_index]
                    -
                    prefix_sum_matrix[row_index][column_index]
                    +
                    grid[row_index][column_index]
                )

                if (prefix_sum_matrix[row_index + 1][column_index + 1]) <= k:
                    valid_submatrices_count += 1

        return valid_submatrices_count


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[[7, 6, 3], [6, 6, 1]], 18],
        [[[7, 2, 9], [1, 5, 0], [2, 6, 6]], 20],
        [[[7, 2], [8, 3], [5, 1], [5, 2]], 17],
    ]

    for testcase in testcases_list:
        print(sol.countSubmatrices(*testcase))
