from dataclasses import dataclass
from typing import List


@dataclass
class DPStatePair:
    maximum_product: int = 0
    minimum_product: int = 0


class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0

        GRID_MATRIX_ROWS_NUMBER = len(grid)
        GRID_MATRIX_COLUMNS_NUMBER = len(grid[0])

        maximum_product = -float('inf')
        dp_state_matrix = [
            [DPStatePair() for _ in range(GRID_MATRIX_COLUMNS_NUMBER)]
            for _ in range(GRID_MATRIX_ROWS_NUMBER)
        ]

        (dp_state_matrix[0][0]).maximum_product = (grid[0][0])
        (dp_state_matrix[0][0]).minimum_product = (grid[0][0])

        for row_index, row in enumerate(grid):
            for column_index, current_cell_value in enumerate(row):
                if (row_index > 0) and (column_index > 0):
                    previous_cells_maximum_product = max(
                        (
                            (
                                dp_state_matrix[row_index][column_index - 1]
                            ).maximum_product
                        ),
                        (
                            (
                                dp_state_matrix[row_index - 1][column_index]
                            ).maximum_product
                        )
                    )
                    previous_cells_minimum_product = min(
                        (
                            (
                                dp_state_matrix[row_index][column_index - 1]
                            ).minimum_product
                        ),
                        (
                            (
                                dp_state_matrix[row_index - 1][column_index]
                            )
                            .minimum_product
                        )
                    )
                elif (row_index > 0):
                    previous_cells_maximum_product = (
                        (
                            dp_state_matrix[row_index - 1][column_index]
                        ).maximum_product
                    )
                    previous_cells_minimum_product = (
                        (
                            dp_state_matrix[row_index - 1][column_index]
                        ).minimum_product
                    )
                elif (column_index > 0):
                    previous_cells_maximum_product = (
                        (
                            dp_state_matrix[row_index][column_index - 1]
                        ).maximum_product
                    )
                    previous_cells_minimum_product = (
                        (
                            dp_state_matrix[row_index][column_index - 1]
                        ).minimum_product
                    )
                else:
                    continue

                if current_cell_value >= 0:
                    (
                        dp_state_matrix[row_index][column_index]
                    ).maximum_product = (
                        current_cell_value * previous_cells_maximum_product
                    )
                    (
                        dp_state_matrix[row_index][column_index]
                    ).minimum_product = (
                        current_cell_value * previous_cells_minimum_product
                    )
                else:
                    (
                        dp_state_matrix[row_index][column_index]
                    ).maximum_product = (
                        current_cell_value * previous_cells_minimum_product
                    )
                    (
                        dp_state_matrix[row_index][column_index]
                    ).minimum_product = (
                        current_cell_value * previous_cells_maximum_product
                    )

        if (
            (
                (
                    dp_state_matrix[
                        GRID_MATRIX_ROWS_NUMBER - 1
                    ][
                        GRID_MATRIX_COLUMNS_NUMBER - 1
                    ]
                ).maximum_product
            )
            <
            0
        ):
            return -1

        return (
            (
                (
                    dp_state_matrix[
                        GRID_MATRIX_ROWS_NUMBER - 1
                    ][
                        GRID_MATRIX_COLUMNS_NUMBER - 1
                    ]
                ).maximum_product
            )
            %
            1000000007
        )


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[[-1, -2, -3], [-2, -3, -3], [-3, -3, -2]]],
        [[[1, -2, 1], [1, -2, 1], [3, -4, 1]]],
        [[[1, 3], [0, -4]]],
    ]

    for testcase in testcases_list:
        print(sol.maxProductPath(*testcase))
