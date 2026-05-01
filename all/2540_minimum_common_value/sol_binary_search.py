from bisect import bisect_left
from typing import List


class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        shorter_list = nums1 if len(nums1) < len(nums2) else nums2
        longer_list = nums1 if len(nums1) >= len(nums2) else nums2
        longer_list_length = len(longer_list)

        for num in shorter_list:
            first_greater_than_or_equal_index = bisect_left(longer_list, num)

            if first_greater_than_or_equal_index >= longer_list_length:
                # Since shorter list is sorted in the ascending order,
                # and if the first index in the longer list whose value
                # is greater than or equal to the current iteated value in
                # the shorter list, we can break the loop since all the
                # following uniterated values won't be common value for sure.
                break
            elif (num == (longer_list[first_greater_than_or_equal_index])):
                return num

        return -1


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 2, 3], [2, 4]],
        [[1, 2, 3, 6], [2, 3, 4, 5]]
    ]

    for testcase in testcases_list:
        print(sol.getCommon(*testcase))
