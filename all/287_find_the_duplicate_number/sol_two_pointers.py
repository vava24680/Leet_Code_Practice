from typing import List


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow_pointer = 0
        fast_pointer = 0

        # Use the check if a linked list has ring algorithm to make slow pointer
        # and fast pointer point to the same node.
        while True:
            slow_pointer = nums[slow_pointer]
            fast_pointer = nums[nums[fast_pointer]]

            if slow_pointer == fast_pointer:
                break

        # Make the slow pointer point to the head node.
        slow_pointer = 0

        # Find the cycle start node.
        while slow_pointer != fast_pointer:
            slow_pointer = nums[slow_pointer]
            fast_pointer = nums[fast_pointer]

        return slow_pointer


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 3, 4, 2, 2]],
        [[3, 1, 3, 4, 2]],
        [[3, 3, 3, 3, 3]],
    ]

    for testcase in testcases_list:
        print(sol.findDuplicate(*testcase))
