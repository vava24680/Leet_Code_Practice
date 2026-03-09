from typing import List


class Solution:
    def _isStrictlyIncreasingSubarray(
        self,
        nums: List[int],
        start_index: int,
        length: int
    ):
        return all(
            nums[start_index + i] > nums[start_index + i - 1]
            for i in range(1, length)
        )

    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        for i in range(len(nums) - (2 * k) + 1):
            # Use fixed size sliding window to get a subarray whose length is
            # 2k, and check if the first half and the last half of that
            # subarray are both strictly increasing.
            if (
                self._isStrictlyIncreasingSubarray(nums, i, k)
                and
                self._isStrictlyIncreasingSubarray(nums, i + k, k)
            ):
                return True

        return False


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[2, 5, 7, 8, 9, 2, 3, 4, 3, 1], 3],
        [[1, 2, 3, 4, 4, 4, 4, 5, 6, 7], 5],
    ]

    for testcase in testcases_list:
        print(sol.hasIncreasingSubarrays(*testcase))
