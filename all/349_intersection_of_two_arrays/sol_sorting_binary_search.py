from bisect import bisect_left
from typing import List


class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result_set = set()
        shorter_list = nums1 if len(nums1) < len(nums2) else nums2
        longer_list = nums1 if len(nums1) >= len(nums2) else nums2
        longer_list_length = len(longer_list)

        longer_list.sort()
        shorter_list.sort()

        for index, num in enumerate(shorter_list):
            if index and ((shorter_list[index - 1]) == num):
                continue

            first_index = bisect_left(longer_list, num)

            if (
                (first_index >= longer_list_length)
                or
                (num != longer_list[first_index])
            ):
                continue

            result_set.add(num)

        return list(result_set)


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 2, 2, 1], [2, 2]],
        [[4, 9, 5], [9, 4, 9, 8, 4]],
    ]

    for testcase in testcases_list:
        print(sol.intersection(*testcase))
