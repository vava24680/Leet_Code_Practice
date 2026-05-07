from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        nums1_idx = m - 1
        nums2_idx = n - 1
        next_smaller_element_index = m + n - 1

        while ((nums1_idx >= 0) and (nums2_idx >= 0)):
            # Start from end to put elements in the nums1 list.
            if (nums1[nums1_idx]) > (nums2[nums2_idx]):
                nums1[next_smaller_element_index] = (nums1[nums1_idx])
                nums1_idx -= 1
            else:
                nums1[next_smaller_element_index] = (nums2[nums2_idx])
                nums2_idx -= 1

            next_smaller_element_index -= 1

        while nums2_idx >= 0:
            # If nums2_idx is greater than or equal to 0, it means there is at
            # least one element is not put into nums1 list, use simple while
            # loop to put those elements to nums1 list.
            nums1[next_smaller_element_index] = (nums2[nums2_idx])
            next_smaller_element_index -= 1
            nums2_idx -= 1


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 2, 3, 0, 0, 0], 3, [2, 5, 6], 3],
        [[1], 1, [], 0],
        [[0], 0, [1], 1],
    ]

    for testcase in testcases_list:
        sol.merge(*testcase)

        print(testcase[0])
