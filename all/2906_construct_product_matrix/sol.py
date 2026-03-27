from typing import List


MODULO = 12345


class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        if not grid:
            return []

        GRID_MATRIX_ROWS_NUMBER = len(grid)
        GRID_MATRIX_COLUMNS_NUMBER = len(grid[0])

        answer_matrix = [
            [1] * GRID_MATRIX_COLUMNS_NUMBER
            for _ in range(GRID_MATRIX_ROWS_NUMBER)
        ]
        previous_prefix_product = 1
        previous_suffix_product = 1

        for row_index, row in enumerate(grid):
            for column_index, current_cell_value in enumerate(row):
                the_other_cell_row_index = (
                    GRID_MATRIX_ROWS_NUMBER - 1 - row_index
                )
                the_other_cell_column_index = (
                    GRID_MATRIX_COLUMNS_NUMBER - 1 - column_index
                )
                answer_matrix[row_index][column_index] = (
                    ((answer_matrix[row_index][column_index]) * previous_prefix_product)
                    %
                    MODULO
                )
                answer_matrix[
                    the_other_cell_row_index
                ][
                    the_other_cell_column_index
                ] = (
                    (
                        (
                            answer_matrix[
                                the_other_cell_row_index
                            ][
                                the_other_cell_column_index
                            ]
                        )
                        *
                        previous_suffix_product
                    )
                    %
                    MODULO
                )
                previous_prefix_product = (
                    (current_cell_value * previous_prefix_product) % MODULO
                )
                previous_suffix_product = (
                    (
                        (
                            grid[
                                the_other_cell_row_index
                            ][
                                the_other_cell_column_index
                            ]
                        )
                        *
                        previous_suffix_product
                    )
                    %
                    MODULO
                )

        return answer_matrix


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[[1, 2], [3, 4]]],
        [[[12345], [2], [1]]]
    ]

    for testcase in testcases_list:
        print(sol.constructProductMatrix(*testcase))
