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
            # We use two pointers to find all unique values that are the list 1
            # but not in the list 2.
            i = 0
            j = 0
            values_list = list()

            while (i < len(list_1)) and (j < len(list_2)):
                # As list_1[i] is equal to list_2[j], it cannot be the value
                # we want, just increase the index i and the index j by 1.
                # The index j is also increased since all values in the list 1
                # and the list 2 are unique. There won't be other elements
                # whose value is list_1[i] in the rest of list 1.
                if (list_1[i]) == (list_2[j]):
                    i += 1
                    j += 1
                elif (list_1[i]) > (list_2[j]):
                    # As list_1[i] is greater than list_2[j], we do not know
                    # whether list_1[i] only shows in the int array 1, we need
                    # to increase the index j by 1 to check more values.
                    j += 1
                else:
                    # As list_1[i] is less than list_2[j], and since list 2 is
                    # sorted, we cannot find list_1[i] in the list_2[j:],
                    # so list_1[i] must only show in the list 1.
                    # Also, all values in the given int array 1 are unique,
                    # we can add list_1[i] to answer array.
                    values_list.append(list_1[i])

                    i += 1

            while (i < len(list_1)):
                # If we still not reach the end of list 1, the rest of values in
                # the list 1 must also shows in list 1 only, we need to add them
                # to answer list too.
                values_list.append(list_1[i])

                i += 1

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
