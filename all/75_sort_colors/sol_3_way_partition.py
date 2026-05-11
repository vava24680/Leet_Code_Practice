from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        next_0_index = 0
        next_2_index = (len(nums) - 1)
        current_index = 0

        # Use 3-way partition to sort a list only having three values.
        while current_index <= next_2_index:
            if 0 == (nums[current_index]):
                nums[next_0_index], nums[current_index] = (
                    nums[current_index], nums[next_0_index]
                )

                next_0_index += 1
                current_index += 1
            elif 2 == (nums[current_index]):
                nums[next_2_index], nums[current_index] = (
                    nums[current_index], nums[next_2_index]
                )

                next_2_index -= 1
            else:
                current_index += 1


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
