from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # dp_state_list is the pointer of DP state array.
        #
        # dp_state_list[i] represents if we can jump to index i from
        # index 0.
        #
        # dp_state_list[0] is always true.
        # dp_state_list[i] is true if there is index j who is smaller than i
        # and dp_state_list[j] is true and we can jump to index i from index j,
        # which means (j + (nums[j])) >= i.
        dp_state_list = [False] * len(nums)
        dp_state_list[0] = True

        for i in range(1, len(nums)):
            dp_state_list[i] = any(
                dp_state_list[j] and ((j + (nums[j])) >= i) for j in range(i)
            )

        return dp_state_list[-1]


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[2, 3, 1, 1, 4]],
        [[3, 2, 1, 0, 4]],
    ]

    for testcase in testcases_list:
        print(sol.canJump(*testcase))
