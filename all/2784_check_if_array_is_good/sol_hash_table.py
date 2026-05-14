from collections import Counter
from typing import List


class Solution:
    def isGood(self, nums: List[int]) -> bool:
        if not nums:
            return False

        values_counter = Counter()
        maximum_value = (-float('inf'))

        for num in nums:
            values_counter[num] += 1
            maximum_value = max(maximum_value, num)

        if (len(nums)) != (maximum_value + 1):
            # If the length of nums list does not equal to the largest value
            # in the nums list plus 1, nums list cannot be a good list.
            return False

        for i in range(1, maximum_value):
            # Make sure every value from 1 to (maximum value - 1) all show only
            # once in the nums list.
            if 1 != (values_counter[i]):
                return False

        # Make sure maximum value shows twice in the nums list.
        return (2 == (values_counter[maximum_value]))


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[2, 1, 3]],
        [[1, 3, 3, 2]],
        [[1, 1]],
        [[3, 4, 4, 1, 2, 1]],
    ]

    for testcase in testcases_list:
        print(sol.isGood(*testcase))
