from typing import List


class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        nums1_length = len(nums1)
        nums2_length = len(nums2)
        index_1 = 0
        index_2 = 0

        while (index_1 < nums1_length) and (index_2 < nums2_length):
            if (nums1[index_1]) == (nums2[index_2]):
                return nums1[index_1]
            elif (nums1[index_1]) > (nums2[index_2]):
                # Since nums1[index_1] is greater than nums2[index_2] and
                # nums2 is sorted in ascending order, there won't any value
                # in the nums2[:index_2 + 1] that can be equal to or greater
                # than nums1[index_1].
                # So increase index_2 by 1 for possible larger value to be
                # checked with nums1[index_1].
                index_2 += 1
            else:
                # Since nums1[index_1] is smaller than nums2[index_2] and
                # nums1 is sorted in ascending order, there won't any value
                # in the nums1[:index_1 + 1] that can be equal to or greater
                # than nums2[index_2].
                # So increase index_1 by 1 for possible larger value to be
                # checked with nums2[index_2].
                index_1 += 1

        return -1


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 2, 3], [2, 4]],
        [[1, 2, 3, 6], [2, 3, 4, 5]]
    ]

    for testcase in testcases_list:
        print(sol.getCommon(*testcase))
