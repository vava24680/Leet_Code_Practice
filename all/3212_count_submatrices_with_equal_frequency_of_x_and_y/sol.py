from typing import List


class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        GRID_MATRIX_ROWS_NUMBER = len(grid)
        GRID_MATRIX_COLUMNS_NUMBER = len(grid[0])

        valid_submatrices_count = 0
        previous_row_prefix_sum_list = [
            [0, 0] for _ in range(GRID_MATRIX_COLUMNS_NUMBER + 1)
        ]
        current_row_prefix_sum_list = [
            [0, 0] for _ in range(GRID_MATRIX_COLUMNS_NUMBER + 1)
        ]

        for row_index, row in enumerate(grid):
            for column_index, c in enumerate(row):
                total_x_characters_count = (
                    previous_row_prefix_sum_list[column_index + 1][0]
                    +
                    current_row_prefix_sum_list[column_index][0]
                    -
                    previous_row_prefix_sum_list[column_index][0]
                )
                total_y_characters_count = (
                    previous_row_prefix_sum_list[column_index + 1][1]
                    +
                    current_row_prefix_sum_list[column_index][1]
                    -
                    previous_row_prefix_sum_list[column_index][1]
                )

                if 'X' == c:
                    total_x_characters_count += 1
                elif 'Y' == c:
                    total_y_characters_count += 1

                if (
                    (total_x_characters_count >= 1)
                    and
                    (total_x_characters_count == total_y_characters_count)
                ):
                    valid_submatrices_count += 1

                current_row_prefix_sum_list[column_index + 1][0] = (
                    total_x_characters_count
                )
                current_row_prefix_sum_list[column_index + 1][1] = (
                    total_y_characters_count
                )

            previous_row_prefix_sum_list, current_row_prefix_sum_list = (
                current_row_prefix_sum_list, previous_row_prefix_sum_list
            )

        return valid_submatrices_count


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[['X', 'Y', '.'], ['Y', '.', '.']]],
        [[['X', 'X'], ['X', 'Y']]],
        [[['.', '.'], ['.', '.']]],
    ]

    for testcase in testcases_list:
        print(sol.numberOfSubmatrices(*testcase))
