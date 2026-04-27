from typing import List


class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return list(set(nums1).intersection(set(nums2)))


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 2, 2, 1], [2, 2]],
        [[4, 9, 5], [9, 4, 9, 8, 4]],
    ]

    for testcase in testcases_list:
        print(sol.intersection(*testcase))
