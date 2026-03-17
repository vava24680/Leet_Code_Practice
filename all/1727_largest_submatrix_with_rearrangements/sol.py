from typing import List


class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        if not matrix:
            return 0

        MATRIX_ROWS_NUMBER = len(matrix)
        MATRIX_COLUMNS_NUMBER = len(matrix[0])

        largest_area = 0

        # Count how many consecutive ones at each position in a column.
        for row_index in range(1, MATRIX_ROWS_NUMBER):
            for column_index in range(MATRIX_COLUMNS_NUMBER):
                if matrix[row_index][column_index]:
                    matrix[row_index][column_index] += (
                        matrix[row_index - 1][column_index]
                    )

        for row in matrix:
            # Sort the consecutive ones count in each row in decreasing order.
            row.sort(reverse=True)

            # Try every possible rectangles that be formed by using current row
            # as the bottom border.
            #
            # Length of the bottom border will continue to expand until we
            # encounter a 0, which means the height of rectangle will be 0.
            for column_index, current_minimum_height in enumerate(row):
                if 0 == current_minimum_height:
                    break

                largest_area = max(
                    largest_area,
                    current_minimum_height * (column_index + 1)
                )

        return largest_area


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[[0, 0, 1], [1, 1, 1], [1, 0, 1]]],
        [[[1, 0, 1, 0, 1]]],
        [[[1, 1, 0], [1, 0, 1]]],
    ]

    for testcase in testcases_list:
        print(sol.largestSubmatrix(*testcase))
