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
        maximum_k = 0

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

        for i in range(nums_length - 1):
            maximum_k = max(
                maximum_k,
                min(
                    maximum_subarrays_length_left[i],
                    maximum_subarrays_length_right[i + 1]
                )
            )

        return maximum_k


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[2, 5, 7, 8, 9, 2, 3, 4, 3, 1]],
        [[1, 2, 3, 4, 4, 4, 4, 5, 6, 7]],
    ]

    for testcase in testcases_list:
        print(sol.maxIncreasingSubarrays(*testcase))
