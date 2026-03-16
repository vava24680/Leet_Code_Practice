from typing import List


class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        domino_values_counter_list = [0] * 100

        # Compute each domino's value and their count.
        for a, b in dominoes:
            # Use normalization to make a domino like (a, b) and the rotated
            # domino like (b, a) can have the same domino value.
            domino_values_counter_list[(max(a, b) * 10) + min(a, b)] += 1

        # After computing each domino value's count, we can use that information
        # to compute how many domino pairs are the same.
        # If a domino value's count is x, there can be
        # ((1 + (x - 1)) * (x - 1)) / 2 pairs of dominoes are considered
        # equivalent.
        return sum(
            (((1 + (count - 1)) * (count - 1)) >> 1)
            for count in domino_values_counter_list
        )


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[[1, 2], [2, 1], [3, 4], [5, 6]]],
        [[[1, 2], [1, 2], [1, 1], [1, 2], [2, 2]]],
    ]

    for testcase in testcases_list:
        print(sol.numEquivDominoPairs(*testcase))
