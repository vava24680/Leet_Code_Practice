from typing import List


class Solution:
    def findDifference(
        self,
        nums1: List[int],
        nums2: List[int]
    ) -> List[List[int]]:
        nums1_values_set = set(nums1)
        nums2_values_set = set(nums2)
        answer_list = [
            list(nums1_values_set.difference(nums2_values_set)),
            list(nums2_values_set.difference(nums1_values_set))
        ]

        return answer_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 2, 3], [2, 4, 6]],
        [[1, 2, 3, 3], [1, 1, 2, 2]],
    ]

    for testcase in testcases_list:
        print(sol.findDifference(*testcase))
