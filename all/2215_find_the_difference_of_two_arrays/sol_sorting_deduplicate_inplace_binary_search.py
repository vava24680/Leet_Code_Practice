from bisect import bisect_left
from typing import List


def deduplicateSortedList(sorted_list: List[int]) -> None:
    next_unique_element_index = 1

    for i in range(1, len(sorted_list)):
        if (sorted_list[i - 1]) == (sorted_list[i]):
            # Skip repeated values.
            continue

        # Move the current found unique value to the position that
        # the next_unique_element_index points to.
        sorted_list[next_unique_element_index] = (sorted_list[i])
        next_unique_element_index += 1

    # Only preserve the part with all the unique values.
    del sorted_list[next_unique_element_index:]

class Solution:
    def findDifference(
        self,
        nums1: List[int],
        nums2: List[int]
    ) -> List[List[int]]:
        answer_list = list()

        # Sort the nums1 list in the ascending order.
        nums1.sort()

        # Sort the nums2 list in the ascending order.
        nums2.sort()

        # Deduplicate the nums1 list inplace.
        deduplicateSortedList(nums1)

        # Deduplicate the nums2 list inplace.
        deduplicateSortedList(nums2)

        def getDifferenceBetweenTwoIntListsValues(
            list_1: List[int],
            list_2: List[int]
        ) -> List[int]:
            # Assume list 1 and list 2 are both sorted in the ascending order
            # and both lists have unique values.
            #
            # We use binary search to find all unique values that are the list 1
            # but not in the list 2.
            list_2_length = len(list_2)
            values_list = list()

            for i in range(len(list_1)):
                # Use binary search to find the first whose element is equal to
                # or greater than list_1[i].
                first_greater_than_or_equal_index = bisect_left(
                    list_2,
                    list_1[i]
                )

                if (
                    (first_greater_than_or_equal_index < list_2_length)
                    and
                    ((list_1[i]) == (list_2[first_greater_than_or_equal_index]))
                ):
                    # If list_1[i] shows in list 2, continue to try next
                    # list_1[i].
                    continue

                # Current iterated list_1[i] does not in list 2, add it to
                # answer list.
                values_list.append(list_1[i])

            return values_list

        answer_list.append(getDifferenceBetweenTwoIntListsValues(nums1, nums2))
        answer_list.append(getDifferenceBetweenTwoIntListsValues(nums2, nums1))

        return answer_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 2, 3], [2, 4, 6]],
        [[1, 2, 3, 3], [1, 1, 2, 2]],
    ]

    for testcase in testcases_list:
        print(sol.findDifference(*testcase))
