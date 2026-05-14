from typing import List


class Solution:
    def isGood(self, nums: List[int]) -> bool:
        if not nums:
            return False

        # Sort the given nums list in the ascending order.
        nums.sort()

        if (len(nums)) != ((nums[-1]) + 1):
            # If the length of nums list does not equal to the largest value
            # in the nums list plus 1, nums list cannot be a good list.
            return False

        for i in range(1, (nums[-1]) + 1):
            # Make sure 1 to nums[-1] all show in the nums list in the right
            # order.
            if i != (nums[i - 1]):
                return False

        return True


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[2, 1, 3]],
        [[1, 3, 3, 2]],
        [[1, 1]],
        [[3, 4, 4, 1, 2, 1]],
    ]

    for testcase in testcases_list:
        print(sol.isGood(*testcase))
