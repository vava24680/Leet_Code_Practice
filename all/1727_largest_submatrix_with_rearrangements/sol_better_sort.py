from typing import List


class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        if not matrix:
            return 0

        MATRIX_ROWS_NUMBER = len(matrix)
        MATRIX_COLUMNS_NUMBER = len(matrix[0])

        largest_area = 0

        previous_row_sorted_heights_list = [
            (0, column_index) for column_index in range(MATRIX_COLUMNS_NUMBER)
        ]
        current_row_sorted_heights_list = [None] * MATRIX_COLUMNS_NUMBER

        for row in matrix:
            # Use the sorted heights result in the previous row to construct the
            # sorted heights result in the current row.
            # Check notes for the detailed sorting logic.
            next_available_index_from_front = 0
            next_available_index_from_rear = (MATRIX_COLUMNS_NUMBER - 1)

            for height, column_index in previous_row_sorted_heights_list:
                if row[column_index]:
                    # A column has at least height 1 in the current row.
                    current_row_sorted_heights_list[
                        next_available_index_from_front
                    ] = (height + 1, column_index)

                    next_available_index_from_front += 1
                else:
                    # A column does not have height in the current row.
                    current_row_sorted_heights_list[
                        next_available_index_from_rear
                    ] = (0, column_index)

                    next_available_index_from_rear -= 1

            # Try every possible rectangles that be formed by using current row
            # as the bottom border.
            #
            # Length of the bottom border will continue to expand until we
            # encounter a 0, which means the height of rectangle will be 0.
            for i, (height, _) in enumerate(current_row_sorted_heights_list):
                if 0 == height:
                    break

                largest_area = max(largest_area, height * (i + 1))

            (
                previous_row_sorted_heights_list,
                current_row_sorted_heights_list
            ) = (
                current_row_sorted_heights_list,
                previous_row_sorted_heights_list
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
