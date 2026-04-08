import functools
import operator

from typing import List


class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        for left_index, right_index, step, multiplier in queries:
            for i in range(left_index, right_index + 1, step):
                nums[i] = ((nums[i] * multiplier) % 1000000007)

        return functools.reduce(operator.xor, nums, 0)


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 1, 1], [[0, 2, 1, 4]]],
        [[2, 3, 1, 5, 4], [[1, 4, 2, 3] , [0, 2, 1, 2]]],
    ]

    for testcase in testcases_list:
        print(sol.xorAfterQueries(*testcase))
