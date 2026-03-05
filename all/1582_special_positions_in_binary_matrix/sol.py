from typing import List


class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        MATRIX_ROWS_NUMBER = len(mat)
        MATRIX_COLUMNS_NUMBER = len(mat[0])

        special_positions_count = 0

        per_row_ones_list = [0] * MATRIX_ROWS_NUMBER
        per_column_ones_list = [0] * MATRIX_COLUMNS_NUMBER

        # Count how many 0 in each row and each column.
        for row_index, row in enumerate(mat):
            for column_index, value in enumerate(row):
                if not value:
                    continue

                per_row_ones_list[row_index] += 1
                per_column_ones_list[column_index] += 1

        # Count how many positions are special in the given binary matrix.
        for row_index, row in enumerate(mat):
            for column_index, value in enumerate(row):
                if not value:
                    continue

                if (
                    (1 == per_row_ones_list[row_index])
                    and
                    (1 == per_column_ones_list[column_index])
                ):
                    special_positions_count += 1

        return special_positions_count


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[[1, 0, 0], [0, 0, 1], [1, 0, 0]]],
        [[[1, 0, 0], [0, 1, 0], [0, 0, 1]]],
    ]

    for testcase in testcases_list:
        print(sol.numSpecial(*testcase))
