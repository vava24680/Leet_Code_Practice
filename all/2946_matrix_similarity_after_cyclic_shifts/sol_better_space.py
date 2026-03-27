from typing import List


class Solution:
    def areSimilar(self, matrix: List[List[int]], k: int) -> bool:
        if not matrix:
            return True

        MATRIX_ROWS_NUMBER = len(matrix)
        MATRIX_COLUMNS_NUMBER = len(matrix[0])

        # Check even rows.
        for column_index in range(MATRIX_COLUMNS_NUMBER):
            new_column_index = (
                (
                    ((column_index - k) % MATRIX_COLUMNS_NUMBER)
                    +
                    MATRIX_COLUMNS_NUMBER
                )
                %
                MATRIX_COLUMNS_NUMBER
            )

            for row_index in range(0, MATRIX_ROWS_NUMBER, 2):
                if (
                    (matrix[row_index][new_column_index])
                    !=
                    (matrix[row_index][column_index])
                ):
                    # If the value in the origianl cell is different from
                    # the value in the new cell, it means the modified matrix
                    # cannot be as same as the original matrix.
                    return False

        # Check odd rows.
        for column_index in range(MATRIX_COLUMNS_NUMBER):
            new_column_index = (
                (
                    ((column_index + k) % MATRIX_COLUMNS_NUMBER)
                    +
                    MATRIX_COLUMNS_NUMBER
                )
                %
                MATRIX_COLUMNS_NUMBER
            )

            for row_index in range(1, MATRIX_ROWS_NUMBER, 2):
                if (
                    (matrix[row_index][new_column_index])
                    !=
                    (matrix[row_index][column_index])
                ):
                    # If the value in the origianl cell is different from
                    # the value in the new cell, it means the modified matrix
                    # cannot be as same as the original matrix.
                    return False

        return True


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[[1, 2, 3], [4, 5, 6], [7, 8, 9]], 4],
        [[[1, 2, 1, 2], [5, 5, 5, 5], [6, 3, 6, 3]], 2],
        [[[2, 2], [2, 2]], 3]
    ]

    for testcase in testcases_list:
        print(sol.areSimilar(*testcase))
