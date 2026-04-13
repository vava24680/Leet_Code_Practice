from typing import List


class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        return min(
            abs(index - start)
            for index, num in enumerate(nums) if num == target
        )


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 2, 3, 4, 5], 5, 3],
        [[1], 1, 0],
        [[1, 1, 1, 1, 1, 1, 1, 1, 1, 1], 1, 0]
    ]

    for testcase in testcases_list:
        print(sol.getMinDistance(*testcase))
