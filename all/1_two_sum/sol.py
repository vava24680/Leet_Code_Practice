from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index_hash_table = {}

        for i, num in enumerate(nums):
            difference = target - num

            if difference in index_hash_table:
                return [index_hash_table[difference], i]

            # Add current element into hash table.
            index_hash_table[num] = i

        return []


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[2, 7, 11, 15], 9],
        [[3, 2, 4], 6],
        [[3, 3], 6],
    ]

    for testcase in testcases_list:
        print(sol.twoSum(*testcase))
