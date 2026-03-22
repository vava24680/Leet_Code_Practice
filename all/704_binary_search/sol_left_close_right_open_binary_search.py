from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # Use find the first equal to greater than pattern to implement.
        #
        # Since all elements in nums are unique, if the middle element
        # is the target, return middle index directly.
        left_index = 0
        right_index = len(nums)

        while left_index < right_index:
            middle_index = (left_index + ((right_index - left_index) >> 1))

            if target == nums[middle_index]:
                return middle_index
            elif nums[middle_index] < target:
                left_index = middle_index + 1
            else:
                right_index = middle_index

        return -1


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[-1, 0, 3, 5, 9, 12], 9],
        [[-1, 0, 3, 5, 9, 12], 2]
    ]

    for testcase in testcases_list:
        print(sol.search(*testcase))
