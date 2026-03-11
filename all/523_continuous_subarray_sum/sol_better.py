from typing import List


class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        remainder_and_first_shown_index_map = {0: -1}
        prefix_sum = 0

        for index, num in enumerate(nums):
            prefix_sum += num
            current_remainder = prefix_sum % k

            if current_remainder not in remainder_and_first_shown_index_map:
                # Record the current remainder and current index in the
                # remainder and first shown index map if current remainder
                # does not show before.
                remainder_and_first_shown_index_map[current_remainder] = index
            elif (
                index - remainder_and_first_shown_index_map[current_remainder]
                >=
                2
            ):
                # Return true if we find a subarray that ends at current
                # element, its length is at least 2 and its sum is the multiple
                # of k.
                return True

        return False


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[23, 2, 4, 6, 7], 6],
        [[23, 2, 6, 4, 7], 6],
        [[23, 2, 6, 4, 7], 13],
    ]

    for testcase in testcases_list:
        print(sol.checkSubarraySum(*testcase))
