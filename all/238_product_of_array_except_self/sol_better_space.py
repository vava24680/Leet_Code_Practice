from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        nums_length = len(nums)
        answer_list = [1] * nums_length
        previous_prefix_product = 1
        previous_suffix_product = 1

        for i, j in zip(range(nums_length), reversed(range(nums_length))):
            answer_list[i] *= previous_prefix_product
            answer_list[j] *= previous_suffix_product

            previous_prefix_product *= nums[i]
            previous_suffix_product *= nums[j]

        return answer_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 2, 3, 4]],
        [[-1, 1, 0, -3, 3]],
    ]

    for testcase in testcases_list:
        print(sol.productExceptSelf(*testcase))
