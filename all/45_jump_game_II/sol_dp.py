from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:
        # dp_state_list is the pointer of DP state array.
        #
        # dp_state_list[i] stores the minimum number jumps to reach index i
        # starting from index 0.
        #
        # 1. dp_state_list[0] is always 0 since we start from index 0,
        #    do not need any jump to reach index 0.
        # 2. dp_state_list[i] (0 < i < n) is float('inf') at the beginning
        #    to denote those indices are not reachable from index 0 at the
        #    beginning.
        # 3. dp_state_list[i] is min(dp_state_list[j] + 1) if:
        #    3.1. i > j >= 0.
        #    3.2. Index j is reachable from index 0.
        #    3.3. j + (nums[j]) >= j.
        dp_state_list = [float('inf')] * len(nums)

        dp_state_list[0] = 0

        for i in range(1, len(nums)):
            dp_state_list[i] = (
                min(
                    (dp_state_list[j] for j in range(i) if (j + (nums[j])) >= i),
                    default=float('inf')
                )
                +
                1
            )

            if float('inf') == (dp_state_list[i]):
                # If current index i is not reachable if start from index 0,
                # it is impossible that we can last index when starting from
                # index 0, return -1 directly.
                return -1

        return dp_state_list[-1]


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[2, 3, 1, 1, 4]],
        [[2, 3, 0, 1, 4]],
        [[3, 0, 0, 1, 0]],
        [[3, 0, 0, 0, 0]],
    ]

    for testcase in testcases_list:
        print(sol.jump(*testcase))
