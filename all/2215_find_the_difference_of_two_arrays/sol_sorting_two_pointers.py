from typing import List


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

        def getDifferenceBetweenTwoIntListsValues(
            list_1: List[int],
            list_2: List[int]
        ) -> List[int]:
            # Assume list 1 and list 2 are both sorted in the ascending order.
            #
            # We use two pointers to find all unique values that are the list 1
            # but not in the list 2.
            i = 0
            j = 0
            values_list = list()

            while (i < len(list_1)) and (j < len(list_2)):
                if (list_1[i]) == (list_2[j]):
                    # As list_1[i] is equal to list_2[j], it cannot be the value
                    # we want, just increase the index i by 1.
                    # The index j is not increased since there might be more
                    # values tha are as same as list_2[j] in the rest of values
                    # in the list 1.
                    i += 1
                elif (list_1[i]) > (list_2[j]):
                    # As list_1[i] is greater than list_2[j], we do not know
                    # whether list_1[i] only shows in the int array 1, we need
                    # to increase the index j by 1 to check more values.
                    j += 1
                else:
                    # As list_1[i] is less than list_2[j], and since
                    # int array 2 is sorted, we cannot find list_1[i] in the
                    # list_2[j:], so list_1[i] must only show in the int array 1.

                    if (not values_list) or ((values_list[-1]) != (list_1[i])):
                        # Only add list_1[i] to answer array if:
                        # 1. Answer array is empty.
                        # 2. list_1[i] is different than the previous value
                        #    added to answer array.
                        values_list.append(list_1[i])

                    i += 1

            while (i < len(list_1)):
                if (not values_list) or ((values_list[-1]) != (list_1[i])):
                    # Only add list_1[i] to answer array if:
                    # 1. Answer array is empty.
                    # 2. list_1[i] is different than the previous value added
                    #    to answer array.
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
