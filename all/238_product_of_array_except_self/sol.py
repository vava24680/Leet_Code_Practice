from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        nums_length = len(nums)
        answer_list = list()

        # prefix_product_array_ptr[i + 1] stores the product of
        # nums[0] * nums[1] * ... * nums[i].
        #
        # prefix_product_array_ptr[0] = 1.
        prefix_product_list = [1] * (len(nums) + 1)

        # suffix_product_array_ptr[i] stores the product of
        # nums[i] * nums[i + 1] * ... * nums[numsSize - 1].
        #
        # suffix_product_array_ptr[numsSize] = 1.
        suffix_product_list = [1] * (len(nums) + 1)

        for i, j in zip(range(nums_length), reversed(range(nums_length))):
            prefix_product_list[i + 1] = (prefix_product_list[i] * nums[i])
            suffix_product_list[j] = (suffix_product_list[j + 1] * nums[j])

        for i in range(nums_length):
            answer_list.append(
                prefix_product_list[i] * suffix_product_list[i + 1]
            )

        return answer_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 2, 3, 4]],
        [[-1, 1, 0, -3, 3]],
    ]

    for testcase in testcases_list:
        print(sol.productExceptSelf(*testcase))
