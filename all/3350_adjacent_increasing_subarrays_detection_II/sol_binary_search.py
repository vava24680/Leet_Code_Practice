from typing import List


class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        nums_length = len(nums)

        # maximum_subarrays_length_left[i] stores the maximum length of the
        # increasing subarray that ends at nums[i].
        maximum_subarrays_length_left = [1] * nums_length

        # maximum_subarrays_length_right[i] stores the maximum length of the
        # increasing subarray that starts at nums[i].
        maximum_subarrays_length_right = [1] * nums_length

        for i in range(1, nums_length):
            if nums[i] > nums[i - 1]:
                maximum_subarrays_length_left[i] = (
                    maximum_subarrays_length_left[i - 1] + 1
                )
            else:
                maximum_subarrays_length_left[i] = 1

            if nums[nums_length - 1 - i] < nums[nums_length - i]:
                maximum_subarrays_length_right[nums_length - 1 - i] = (
                    maximum_subarrays_length_right[nums_length - i] + 1
                )
            else:
                maximum_subarrays_length_right[nums_length - 1 - i] = 1

        # Use binary search to find the first not valid subarray length
        # in all the possible subarray lengths.
        left_subarray_length = 1
        right_subarray_length = (nums_length >> 1) + 1

        while left_subarray_length < right_subarray_length:
            middle_subarray_length = (
                left_subarray_length
                +
                ((right_subarray_length - left_subarray_length) >> 1)
            )

            for i in range(
                middle_subarray_length - 1,
                (nums_length - middle_subarray_length - 1) + 1
            ):
                if (
                    (maximum_subarrays_length_left[i] >= middle_subarray_length)
                    and
                    (maximum_subarrays_length_right[i + 1] >= middle_subarray_length)
                ):
                    left_subarray_length = middle_subarray_length + 1

                    break
            else:
                right_subarray_length = middle_subarray_length

        # Because the subarray we find is the first that is not valid,
        # we need to subtract 1 from it to get the maximum one that is valid.
        return left_subarray_length - 1


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[2, 5, 7, 8, 9, 2, 3, 4, 3, 1]],
        [[1, 2, 3, 4, 4, 4, 4, 5, 6, 7]],
    ]

    for testcase in testcases_list:
        print(sol.maxIncreasingSubarrays(*testcase))
