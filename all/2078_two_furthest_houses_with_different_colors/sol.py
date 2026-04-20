from typing import List


class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        colors_length = len(colors)
        maximum_distance = 0

        for left_index in range(colors_length - 1):
            for right_index in reversed(range(left_index + 1, colors_length)):
                if (colors[left_index]) != (colors[right_index]):
                    # Try every house pair whose colors are different and find
                    # the maximum distance among them.
                    maximum_distance = max(
                        maximum_distance,
                        right_index - left_index
                    )

                    break

        return maximum_distance


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 1, 1, 6, 1, 1, 1]],
        [[1, 8, 3, 8, 3]],
        [[0, 1]],
    ]

    for testcase in testcases_list:
        print(sol.maxDistance(*testcase))
