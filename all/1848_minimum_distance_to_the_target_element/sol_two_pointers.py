from typing import List


class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        left_index = right_index = start

        # Start from the start index and search towards the left side and the
        # right side.
        while (left_index >= 0) or (right_index < len(nums)):
            if left_index >= 0:
                if (target == (nums[left_index])):
                    return (start - left_index)

                left_index -= 1

            if right_index < len(nums):
                if (target == (nums[right_index])):
                    return (right_index - start)

                right_index += 1

        return -1


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 2, 3, 4, 5], 5, 3],
        [[1], 1, 0],
        [[1, 1, 1, 1, 1, 1, 1, 1, 1, 1], 1, 0]
    ]

    for testcase in testcases_list:
        print(sol.getMinDistance(*testcase))
