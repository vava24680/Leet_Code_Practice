from typing import List


class Solution:
    def findRotation(
        self,
        matrix: List[List[int]],
        target: List[List[int]]
    ) -> bool:
        MATRIX_ROWS_NUMBER = len(matrix)
        MATRIX_COLUMNS_NUMBER = len(matrix[0])

        if matrix == target:
            return True

        for rotation_times in range(3):
            # Transpose the matrix and the reverse each row in the matrix have
            # same effect as rotating the matrix 90 degrees clockwise.

            # Transpose the matrix.
            for row_index in range(MATRIX_ROWS_NUMBER):
                for column_index in range(row_index + 1, MATRIX_COLUMNS_NUMBER):
                    (
                        matrix[row_index][column_index],
                        matrix[column_index][row_index]
                    ) = (
                        matrix[column_index][row_index],
                        matrix[row_index][column_index]
                    )

            # Reverse each row in the matrix.
            for row_index in range(MATRIX_ROWS_NUMBER):
                for column_index in range(MATRIX_COLUMNS_NUMBER >> 1):
                    (
                        matrix[row_index][column_index],
                        matrix[
                            row_index
                        ][
                            MATRIX_COLUMNS_NUMBER - 1 - column_index
                        ]
                    )= (
                        matrix[
                            row_index
                        ][
                            MATRIX_COLUMNS_NUMBER - 1 - column_index
                        ],
                        matrix[row_index][column_index]
                    )

            if matrix == target:
                return True

        return False

if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[[0, 1], [1, 0]], [[1, 0], [0, 1]]],
        [[[0, 1], [1, 1]], [[1, 0], [0, 1]]],
        [[[0, 0, 0], [0, 1, 0], [1, 1, 1]], [[1, 1, 1], [0, 1, 0], [0, 0, 0]]],
    ]

    for testcase in testcases_list:
        print(sol.findRotation(*testcase))
