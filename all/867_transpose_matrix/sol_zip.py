from typing import List


class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        return [list(new_row) for new_row in zip(*matrix)]


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[[1, 2, 3], [4, 5, 6], [7, 8, 9]]],
        [[[1, 2, 3], [4, 5, 6]]],
    ]

    for testcase in testcases_list:
        print(sol.transpose(*testcase))
