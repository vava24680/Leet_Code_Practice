from typing import List


class Solution:
    def rotateTheBox(self, boxGrid: List[List[str]]) -> List[List[str]]:
        ORIGINAL_MATRIX_ROWS_NUMBER = len(boxGrid)
        ORIGINAL_MATRIX_COLUMNS_NUMBER = len(boxGrid[0])
        ANSWER_MATRIX_ROWS_NUMBER = ORIGINAL_MATRIX_COLUMNS_NUMBER
        ANSWER_MATRIX_COLUMNS_NUMBER = ORIGINAL_MATRIX_ROWS_NUMBER

        answer_matrix = [
            [0] * ANSWER_MATRIX_COLUMNS_NUMBER
            for _ in range(ANSWER_MATRIX_ROWS_NUMBER)
        ]

        for column_index in reversed(range(ORIGINAL_MATRIX_COLUMNS_NUMBER)):
            new_row_index = column_index

            # Rotate a column in the boxGrid clockwise 90 degrees.
            for row_index in range(ORIGINAL_MATRIX_ROWS_NUMBER):
                new_column_index = ORIGINAL_MATRIX_ROWS_NUMBER - 1 - row_index
                answer_matrix[new_row_index][new_column_index] = (
                    boxGrid[row_index][column_index]
                )

            # A column becomes a row after rotating clockwise 90 degrees.
            # Iterate all cells in that row.
            for iterated_column_index in range(ANSWER_MATRIX_COLUMNS_NUMBER):
                if (
                    (
                        '*'
                        ==
                        (answer_matrix[new_row_index][iterated_column_index])
                    )
                    or
                    (
                        '.'
                        ==
                        (answer_matrix[new_row_index][iterated_column_index])
                    )
                ):
                    # Skip if current box does not contain a ston.e
                    continue

                current_row_index = new_row_index

                # Make a stone falls down until it lands on the boundary,
                # and obstacle or another stone.
                while (
                    ((current_row_index + 1) < ANSWER_MATRIX_ROWS_NUMBER)
                    and
                    (
                        '.'
                        ==
                        (
                            answer_matrix[
                                current_row_index + 1
                            ][
                                iterated_column_index
                            ]
                        )
                    )
                ):
                    answer_matrix[current_row_index][iterated_column_index] = (
                        '.'
                    )
                    answer_matrix[current_row_index + 1][iterated_column_index] = (
                        '#'
                    )

                    current_row_index += 1

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
