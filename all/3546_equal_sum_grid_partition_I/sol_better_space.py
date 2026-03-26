from typing import List


class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        if not grid:
            return False

        GRID_MATRIX_ROWS_NUMBER = len(grid)
        GRID_MATRIX_COLUMNS_NUMBER = len(grid[0])

        row_sum_list = [0] * GRID_MATRIX_ROWS_NUMBER
        column_sum_list = [0] * GRID_MATRIX_COLUMNS_NUMBER
        total_sum = 0

        for row_index, row in enumerate(grid):
            for column_index, current_cell_value in enumerate(row):
                row_sum_list[row_index] += current_cell_value
                column_sum_list[column_index] += current_cell_value
                total_sum += current_cell_value

        # Try every possible horizontal cut.
        accumulated_sum = 0

        for row_index in range(GRID_MATRIX_ROWS_NUMBER - 1):
            accumulated_sum += row_sum_list[row_index]

            if total_sum == (accumulated_sum << 1):
                return True

        # Try every possible vertical cut.
        accumulated_sum = 0

        for column_index in range(GRID_MATRIX_COLUMNS_NUMBER - 1):
            accumulated_sum += column_sum_list[column_index]

            if total_sum == (accumulated_sum << 1):
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
