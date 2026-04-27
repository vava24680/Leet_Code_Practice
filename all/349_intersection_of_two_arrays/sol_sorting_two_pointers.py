from bisect import bisect_left
from typing import List


class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        answer_list = list()

        # Sort the nums1 list in the ascending order.
        nums1.sort()

        # Sort the nums2 list in the ascending order.
        nums2.sort()

        i = 0
        j = 0

        while (i < len(nums1)) and (j < len(nums2)):
            if (nums1[i]) == (nums2[j]):
                # If current iterated two values are the same, we might find a
                # new intersected value.
                if (not answer_list) or ((answer_list[-1]) != (nums1[i])):
                    # Add current iterated value to answer list if it is the
                    # first found intersected element or it is different from
                    # the previous found intersected element.
                    answer_list.append(nums1[i])

                # Increase both pointers by 1.
                i += 1
                j += 1
            elif (nums1[i]) < (nums2[j]):
                # If current iterated value in the nums1 list is less than
                # current iterated value in the nums2 list, we need to increase
                # the pointer for nums1 list by 1 since that value will not show
                # in the rest of sections in the nums2 list.
                i += 1
            else:
                # If current iterated value in the nums2 list is greater than
                # current iterated value in the nums2 list, we need to increase
                # the pointer for nums2 list by 1 since that value will not
                # show in the rest of sections in the nums1 list.
                j += 1

        return answer_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 2, 2, 1], [2, 2]],
        [[4, 9, 5], [9, 4, 9, 8, 4]],
    ]

    for testcase in testcases_list:
        print(sol.intersection(*testcase))
