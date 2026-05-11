from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        colors_count_list = [0, 0, 0]

        # Iterate the given nums array compute each color's count since we need
        # to use counting sort to sort the given nums list.
        for color_index in nums:
            colors_count_list[color_index] += 1

        color_index = 0

        # Iterate from 0 to len(nums) - 1 to fill in all colors in order.
        for i in range(len(nums)):
            while 0 == (colors_count_list[color_index]):
                # Find a color whose count is not 0.
                color_index += 1

            # Fill in current color.
            nums[i] = color_index

            # Decrease current color's count by 1.
            colors_count_list[color_index] -= 1


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[2, 0, 2, 1, 1, 0]],
        [[2, 0, 1]],
        [[2]],
    ]

    for testcase in testcases_list:
        sol.sortColors(*testcase)
        print(testcase[0])
