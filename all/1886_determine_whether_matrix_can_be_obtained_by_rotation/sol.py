from typing import List


class Solution:
    def findRotation(
        self,
        matrix: List[List[int]],
        target: List[List[int]]
    ) -> bool:
        MATRIX_ROWS_NUMBER = len(matrix)
        MATRIX_COLUMNS_NUMBER = len(matrix[0])

        rotated_matrix = [
            [0] * MATRIX_COLUMNS_NUMBER for _ in range(MATRIX_ROWS_NUMBER)
        ]

        # Swap the original matrix and the rotated matrix.
        rotated_matrix, matrix = matrix, rotated_matrix

        for rotation_times in range(0, 4):
            # The following comparision is ok too.
            # if rotated_matrix == target:
            #     return True

            if all(
                row_1 == row_2 for row_1, row_2 in zip(rotated_matrix, target)
            ):
                return True

            # Swap the original matrix and the rotated matrix.
            matrix, rotated_matrix = rotated_matrix, matrix

            for row_index in range(MATRIX_ROWS_NUMBER):
                for column_index in range(MATRIX_COLUMNS_NUMBER):
                    rotated_matrix[
                        column_index
                    ][
                        MATRIX_ROWS_NUMBER - 1 - row_index
                    ] = matrix[row_index][column_index]

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
