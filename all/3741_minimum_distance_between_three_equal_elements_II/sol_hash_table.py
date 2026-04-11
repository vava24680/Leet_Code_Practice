from typing import List


class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        minimum_distance = float('inf')
        value_index_list_mapping_dict = dict()

        for index, num in enumerate(nums):
            if num not in value_index_list_mapping_dict:
                value_index_list_mapping_dict[num] = list()

            value_index_list_mapping_dict[num].append(index)

        for value, index_list in value_index_list_mapping_dict.items():
            if len(index_list) < 3:
                continue

            for i in range(len(index_list) - 3 + 1):
                minimum_distance = min(
                    minimum_distance,
                    (index_list[i + 2] - index_list[i + 1])
                    +
                    (index_list[i + 2] - index_list[i])
                    +
                    (index_list[i + 1] - index_list[i])
                )

        if float('inf') == minimum_distance:
            return -1

        return minimum_distance


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 2, 1, 1, 3]],
        [[1, 1, 2, 3, 2, 1, 2]],
        [[1]],
    ]

    for testcase in testcases_list:
        print(sol.minimumDistance(*testcase))
