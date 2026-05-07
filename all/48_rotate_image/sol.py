from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        MATRIX_ROWS_NUMBER = len(matrix)
        MATRIX_COLUMNS_NUMBER = len(matrix[0])

        # Transpose the given matrix first.
        for row_index in range(MATRIX_ROWS_NUMBER):
            for column_index in range(row_index + 1, MATRIX_COLUMNS_NUMBER):
                (
                    matrix[row_index][column_index],
                    matrix[column_index][row_index]
                ) = (
                    matrix[column_index][row_index],
                    matrix[row_index][column_index]
                )

        # Reverse each row in the given matrix.
        for row in matrix:
            row.reverse()


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[[1, 2, 3] ,[4, 5, 6], [7, 8, 9]]],
        [[[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]]],
    ]

    for testcase in testcases_list:
        sol.rotate(*testcase)
        print(testcase)
