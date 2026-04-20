from typing import List


class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        furthest_different_color_house_index_against_first_house = 0
        furthest_different_color_house_index_against_last_house = (
            len(colors) - 1
        )

        for i in reversed(range(1, len(colors))):
            # Start from the last house, find the first house whose color is
            # different from the first house and record that house's index.
            if (colors[0]) != (colors[i]):
                furthest_different_color_house_index_against_first_house = i

                break

        for i in range(len(colors) - 1):
            # Start from the first house, find the first house whose color is
            # different from the last house and record that house's index.
            if (colors[-1]) != (colors[i]):
                furthest_different_color_house_index_against_last_house = i

                break

        # Check notes for why answer is the larger value among the following two
        # values:
        # 1. The distance between the first house and the first house from the
        #    right side and has different color from the first house.
        # 2. The distance between the last house and the first house from the
        #    left side and has different color from the last house.
        return max(
            furthest_different_color_house_index_against_first_house - 0,
            (
                (len(colors) - 1)
                -
                furthest_different_color_house_index_against_last_house
            )
        )


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 1, 1, 6, 1, 1, 1]],
        [[1, 8, 3, 8, 3]],
        [[0, 1]],
    ]

    for testcase in testcases_list:
        print(sol.maxDistance(*testcase))
