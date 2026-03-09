from typing import List


class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        answer = 0
        current_strictly_increasing_subarray_length = 1
        previous_strictly_increasing_subarray_length = 0

        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                current_strictly_increasing_subarray_length += 1
            else:
                previous_strictly_increasing_subarray_length = (
                    current_strictly_increasing_subarray_length
                )
                current_strictly_increasing_subarray_length = 1

            answer = max(
                answer,
                # A whole strictly increasing is cut in two half case.
                current_strictly_increasing_subarray_length >> 1,
                # Two adjacent but separated strictly increasing subarray case.
                min(
                    current_strictly_increasing_subarray_length,
                    previous_strictly_increasing_subarray_length
                )
            )

        return answer


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[2, 5, 7, 8, 9, 2, 3, 4, 3, 1]],
        [[1, 2, 3, 4, 4, 4, 4, 5, 6, 7]],
    ]

    for testcase in testcases_list:
        print(sol.maxIncreasingSubarrays(*testcase))
