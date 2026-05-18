from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        left_index, right_index = 0, (len(nums) - 1)
        middle_index = 0

        while left_index < right_index:
            middle_index = (left_index + ((right_index - left_index) >> 1))

            if (nums[middle_index]) > (nums[right_index]):
                # Right part is not monotonically increasing, the minimum element
                # is in the right part (middle is excluded).
                left_index = (middle_index + 1)
            elif (nums[middle_index]) < (nums[right_index]):
                # Right part is strictly increasing, the minimum element is in
                # the left part (middle is included).
                right_index = middle_index
            else:
                # Right part seems has all equal values, but it might be a
                # illusion, so we just decrease right index by 1.
                #
                # For example, if nums array is [3, 3, 1, 3], the values at the
                # middle index and the right index are the same, we are not sure
                # if there exists turning point in the right part, so decrease
                # right index by 1 shrink search range. As the values at the
                # middle index and the right index are the same, this search
                # range shrinkage can still preserve the minimum value if the
                # value at the right index is the minimum value.
                right_index -= 1

        return (nums[left_index])


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 3, 5]],
        [[2, 2, 2, 0, 1]],
        [[11, 13, 15, 17]],
        [[1, 3, 3, 3]],
        [[3, 1, 3, 3]],
        [[3, 3, 1, 3]],
        [[3, 3, 3, 1]],
    ]

    for testcase in testcases_list:
        print(sol.findMin(*testcase))
