from typing import List


class Solution:
    def minAbsDiff(self, grid: List[List[int]], k: int) -> List[List[int]]:
        if not grid:
            return []

        GRID_MATRIX_ROWS_NUMBER = len(grid)
        GRID_MATRIX_COLUMNS_NUMBER = len(grid[0])

        answer_list = [
            [0] * (GRID_MATRIX_COLUMNS_NUMBER - k + 1)
            for _ in range(GRID_MATRIX_ROWS_NUMBER - k + 1)
        ]
        list_for_sorting = [0] * (k * k)

        for top_left_row_index in range(GRID_MATRIX_ROWS_NUMBER - k + 1):
            for top_left_column_index in range(
                GRID_MATRIX_COLUMNS_NUMBER - k + 1
            ):
                next_write_index = 0

                for row_index in range(
                    top_left_row_index,
                    top_left_row_index + k
                ):
                    for column_index in range(
                        top_left_column_index,
                        top_left_column_index + k
                    ):
                        list_for_sorting[next_write_index] = (
                            grid[row_index][column_index]
                        )

                        next_write_index += 1

                list_for_sorting.sort()
                minimum_absolute_difference = float('inf')

                for i in range(1, len(list_for_sorting)):
                    if list_for_sorting[i] == list_for_sorting[i - 1]:
                        continue

                    minimum_absolute_difference = min(
                        minimum_absolute_difference,
                        list_for_sorting[i] - list_for_sorting[i - 1]
                    )

                if float('inf') == minimum_absolute_difference:
                    minimum_absolute_difference = 0

                answer_list[top_left_row_index][top_left_column_index] = (
                    minimum_absolute_difference
                )

        return answer_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[[1, 8], [3, -2]], 2],
        [[[3, -1]], 1],
        [[[1, -2, 3], [2, 3, 5]], 2],
    ]

    for testcase in testcases_list:
        print(sol.minAbsDiff(*testcase))
