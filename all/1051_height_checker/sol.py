from typing import List


class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        different_indexes_count = 0

        for value, original_value in zip(sorted(heights), heights):
            if value != original_value:
                different_indexes_count += 1

        return different_indexes_count


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 1, 4, 2, 1, 3]],
        [[5, 1, 2, 3, 4]],
    ]

    for testcase in testcases_list:
        print(sol.heightChecker(*testcase))
