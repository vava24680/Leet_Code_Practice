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

        previous_row_dp_state_list = [
            DPStatePair() for _ in range(GRID_MATRIX_COLUMNS_NUMBER)
        ]
        current_row_dp_state_list = [
            DPStatePair() for _ in range(GRID_MATRIX_COLUMNS_NUMBER)
        ]

        # Construct the DP state for the first row.
        (previous_row_dp_state_list[0]).maximum_product = (grid[0][0])
        (previous_row_dp_state_list[0]).minimum_product = (grid[0][0])

        for column_index in range(1, GRID_MATRIX_COLUMNS_NUMBER):
            (previous_row_dp_state_list[column_index].maximum_product) = (
                (previous_row_dp_state_list[column_index - 1].maximum_product)
                *
                grid[0][column_index]
            )
            (previous_row_dp_state_list[column_index].minimum_product) = (
                (previous_row_dp_state_list[column_index - 1].minimum_product)
                *
                grid[0][column_index]
            )

        # Construct the DP state for the rest of rows except the first row.
        for row_index in range(1, GRID_MATRIX_ROWS_NUMBER):
            # Construct the DP state for the first column in each row.
            current_row_dp_state_list[0].maximum_product = (
                (previous_row_dp_state_list[0].maximum_product)
                *
                (grid[row_index][0])
            )
            current_row_dp_state_list[0].minimum_product = (
                (previous_row_dp_state_list[0].minimum_product)
                *
                (grid[row_index][0])
            )

            # Construct the DP state for rest of columns except the first
            # column within a row.
            for column_index in range(1, GRID_MATRIX_COLUMNS_NUMBER):
                current_cell_value = (grid[row_index][column_index])
                previous_cells_maximum_product = max(
                    (
                        (
                            current_row_dp_state_list[column_index - 1]
                        ).maximum_product
                    ),
                    (
                        (
                            previous_row_dp_state_list[column_index]
                        ).maximum_product
                    )
                )
                previous_cells_minimum_product = min(
                    (
                        (
                            current_row_dp_state_list[column_index - 1]
                        ).minimum_product
                    ),
                    (
                        (
                            previous_row_dp_state_list[column_index]
                        )
                        .minimum_product
                    )
                )

                if current_cell_value >= 0:
                    (
                        current_row_dp_state_list[column_index]
                    ).maximum_product = (
                        current_cell_value * previous_cells_maximum_product
                    )
                    (
                        current_row_dp_state_list[column_index]
                    ).minimum_product = (
                        current_cell_value * previous_cells_minimum_product
                    )
                else:
                    (
                        current_row_dp_state_list[column_index]
                    ).maximum_product = (
                        current_cell_value * previous_cells_minimum_product
                    )
                    (
                        current_row_dp_state_list[column_index]
                    ).minimum_product = (
                        current_cell_value * previous_cells_maximum_product
                    )

            (previous_row_dp_state_list, current_row_dp_state_list) = (
                current_row_dp_state_list, previous_row_dp_state_list
            )

        if (
            (
                (
                    previous_row_dp_state_list[GRID_MATRIX_COLUMNS_NUMBER - 1]
                ).maximum_product
            )
            <
            0
        ):
            return -1

        return (
            (
                (
                    previous_row_dp_state_list[GRID_MATRIX_COLUMNS_NUMBER - 1]
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
