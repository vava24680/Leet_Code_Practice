from typing import List


class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        return [
            [row[column_index] for row in matrix]
            for column_index in range(len(matrix[0]))
        ]


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[[1, 2, 3], [4, 5, 6], [7, 8, 9]]],
        [[[1, 2, 3], [4, 5, 6]]],
    ]

    for testcase in testcases_list:
        print(sol.transpose(*testcase))
