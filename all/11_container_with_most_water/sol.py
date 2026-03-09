from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        maximum_area = 0
        left_index = 0
        right_index = len(height) - 1

        while left_index < right_index:
            left_height = height[left_index]
            right_height = height[right_index]

            maximum_area = max(
                maximum_area,
                min(left_height, right_height) * (right_index - left_index)
            )

            if left_height < right_height:
                # If left height is smaller than right height, increase the left
                # index by 1 to try if there are larger left height to form
                # larger container.
                left_index += 1
            else:
                # If right height is smaller than or equal to left height,
                # decrease the right index by 1 to try if there are larger right
                # height to form larger container.
                right_index -= 1

        return maximum_area


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 8, 6, 2, 5, 4, 8, 3, 7]],
        [[1, 1]],
    ]

    for testcase in testcases_list:
        print(sol.maxArea(*testcase))
