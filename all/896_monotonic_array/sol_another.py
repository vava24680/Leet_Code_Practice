from typing import List


class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        is_strictly_monotonic_increasing = False
        is_strictly_monotonic_decreasing = False

        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                is_strictly_monotonic_decreasing = True
            elif nums[i] < nums[i - 1]:
                is_strictly_monotonic_increasing = True

            if (
                is_strictly_monotonic_increasing
                and
                is_strictly_monotonic_decreasing
            ):
                return False

        return True


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 2, 2, 3]],
        [[6, 5, 4, 4]],
        [[1, 3, 2]],
    ]

    for testcase in testcases_list:
        print(sol.isMonotonic(*testcase))
