from typing import List


class Solution:
    def rotateTheBox(self, boxGrid: List[List[str]]) -> List[List[str]]:
        ORIGINAL_MATRIX_ROWS_NUMBER = len(boxGrid)
        ORIGINAL_MATRIX_COLUMNS_NUMBER = len(boxGrid[0])
        ANSWER_MATRIX_ROWS_NUMBER = ORIGINAL_MATRIX_COLUMNS_NUMBER
        ANSWER_MATRIX_COLUMNS_NUMBER = ORIGINAL_MATRIX_ROWS_NUMBER

        answer_matrix = [
            ['.'] * ANSWER_MATRIX_COLUMNS_NUMBER
            for _ in range(ANSWER_MATRIX_ROWS_NUMBER)
        ]

        for row_index in range(ORIGINAL_MATRIX_ROWS_NUMBER):
            rightmost_available_column_index = (ORIGINAL_MATRIX_COLUMNS_NUMBER - 1)

            for column_index in reversed(range(ORIGINAL_MATRIX_COLUMNS_NUMBER)):
                if '#' == (boxGrid[row_index][column_index]):
                    # Compute the row index and the column index of the location
                    # where current stone will fall down.
                    new_row_index = rightmost_available_column_index
                    new_column_index = (
                        ORIGINAL_MATRIX_ROWS_NUMBER - 1 - row_index
                    )
                    answer_matrix[new_row_index][new_column_index] = '#'

                    rightmost_available_column_index -= 1
                elif '*' == (boxGrid[row_index][column_index]):
                    # If content in the current cell is not stone, it will not
                    # fall after rotation.
                    new_row_index = column_index
                    new_column_index = (
                        ORIGINAL_MATRIX_ROWS_NUMBER - 1 - row_index
                    )
                    answer_matrix[new_row_index][new_column_index] = (
                        boxGrid[row_index][column_index]
                    )

                    # Update rightmost available column index for a stone
                    # if current cell is an obstacle.
                    rightmost_available_column_index = (column_index - 1)

        return answer_matrix


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[['#', '.', '#']]],
        [[['#', '.', '*', '.'], ['#', '#', '*', '.']]],
        [[
            ['#', '#', '*', '.', '*', '.'],
            ['#', '#', '#', '*', '.', '.'],
            ['#', '#', '#', '.', '#', '.'],
        ]],
    ]

    for testcase in testcases_list:
        print(sol.rotateTheBox(*testcase))
