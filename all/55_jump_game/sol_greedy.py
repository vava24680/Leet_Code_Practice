from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # Use this variable to record the furthest index can be reached from
        # the indices that we have traversed.
        furthest_index_can_be_reached = (nums[0])

        for i in range(1, len(nums)):
            if i > furthest_index_can_be_reached:
                # If current index is larger than the furthest index that
                # can be reached from all the previous indices that we have
                # traversed, it is impossible that we can reach current index
                # and further indices, so return false immediately.
                return False

            # Update furthest index that can be reached from all the indices
            # that we have traversed.
            furthest_index_can_be_reached = max(
                furthest_index_can_be_reached,
                i + (nums[i])
            )

        return True


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[2, 3, 1, 1, 4]],
        [[3, 2, 1, 0, 4]],
    ]

    for testcase in testcases_list:
        print(sol.canJump(*testcase))
