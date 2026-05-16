from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        left_index, right_index = 0, (len(nums) - 1)
        middle_index = 0

        while left_index < right_index:
            middle_index = (left_index + ((right_index - left_index) >> 1))

            if (nums[middle_index]) >= (nums[right_index]):
                # Right part is not strictly increasing, the minimum element
                # is in the right part (middle is excluded).
                left_index = (middle_index + 1)
            else:
                # Right part is strictly increasing, the minimum element is in
                # the left part (middle is included).
                right_index = middle_index

        return (nums[left_index])


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[3, 4, 5, 1, 2]],
        [[4, 5, 6, 7, 0, 1, 2]],
        [[11, 13, 15, 17]],
        [[11, 11, 11, 11]],
    ]

    for testcase in testcases_list:
        print(sol.findMin(*testcase))
