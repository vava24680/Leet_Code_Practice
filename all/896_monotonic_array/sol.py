import enum

from typing import List


@enum.unique
class MonotonicStyleEnum(enum.Enum):
    NONE = 0
    INCREASING = 1
    DECREASING = 2


class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        monotonic_style = MonotonicStyleEnum.NONE

        for i in range(1, len(nums)):
            if MonotonicStyleEnum.NONE == monotonic_style:
                if nums[i] > nums[i - 1]:
                    monotonic_style = MonotonicStyleEnum.INCREASING
                elif nums[i] < nums[i - 1]:
                    monotonic_style = MonotonicStyleEnum.DECREASING
            elif (
                (
                    (MonotonicStyleEnum.INCREASING == monotonic_style)
                    and
                    (nums[i] < nums[i - 1])
                )
                or
                (
                    (MonotonicStyleEnum.DECREASING == monotonic_style)
                    and
                    (nums[i] > nums[i - 1])
                )
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
