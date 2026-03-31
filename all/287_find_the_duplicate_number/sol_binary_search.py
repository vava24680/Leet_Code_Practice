from typing import List


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # Use binary search to find the duplicate value.
        # Check notes for details.
        left_value = 0
        right_value = len(nums) - 1

        while left_value < right_value:
            middle_value = (left_value + ((right_value - left_value) >> 1))
            count = 0

            # Count how many numbers in the nums array are less than or equal to
            # the middle value.
            for num in nums:
                if num <= middle_value:
                    count += 1

            if count <= middle_value:
                left_value = middle_value + 1
            else:
                right_value = middle_value

        return left_value


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 3, 4, 2, 2]],
        [[3, 1, 3, 4, 2]],
        [[3, 3, 3, 3, 3]],
    ]

    for testcase in testcases_list:
        print(sol.findDuplicate(*testcase))
