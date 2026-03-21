from typing import List


class Solution:
    def reverseSubmatrix(
        self,
        grid: List[List[int]],
        x: int,
        y: int,
        k: int
    ) -> List[List[int]]:
        for i in range(k >> 1):
            # Use two pointers to point the two rows that should be reversed
            # vertically.
            row_index_1 = (x + i)
            row_index_2 = (x + (k - 1 - i))

            for column_index in range(y, y + k):
                (
                    grid[row_index_1][column_index],
                    grid[row_index_2][column_index]
                )= (
                    grid[row_index_2][column_index],
                    grid[row_index_1][column_index]
                )

        return grid


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [
            [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]],
            1,
            0,
            3
        ],
        [[[3, 4, 2, 3], [2, 3, 4, 2]], 0, 2, 2],
    ]

    for testcase in testcases_list:
        print(sol.reverseSubmatrix(*testcase))
