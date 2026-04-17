from typing import List


class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        minimum_distance = float('inf')
        value_to_index_mapping_dict = dict()

        for index in reversed(range(len(nums))):
            # Iterate all the num in the nums list from back to front.

            # Get current iterated number.
            num = (nums[index])

            # Compute reversed number.
            reversed_num = int((str(num)[::-1]))

            # Get the first index that is larger than the current iterated index
            # and that index has the of reversed number in the nums list.
            first_larger_index = value_to_index_mapping_dict.get(reversed_num)

            if first_larger_index is not None:
                # If first larger index exists, it means we can use index i and that
                # index to form a mirror pair, and this mirror pair's distance
                # must be shortest among all the mirror pairs whose first index
                # is the current iterated index, which means its distance can
                # compete with the global recorded one.
                #
                # After computing the distance of current mirror pair, we can
                # update global recorded one if needed.
                minimum_distance = min(
                    minimum_distance,
                    first_larger_index - index
                )

            # Add current iterated index to a corresponding indices list.
            value_to_index_mapping_dict[num] = index

        if float('inf') == minimum_distance:
            return -1

        return minimum_distance


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[12, 21, 45, 33, 54]],
        [[120, 21]],
        [[21, 120]],
    ]

    for testcase in testcases_list:
        print(sol.minMirrorPairDistance(*testcase))
