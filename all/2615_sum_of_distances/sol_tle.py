from typing import List


class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        answer_list = list()
        value_to_indices_list_mapping_dict = dict()

        # Construct value to indices list mapping.
        for index, value in enumerate(nums):
            if value not in value_to_indices_list_mapping_dict:
                value_to_indices_list_mapping_dict[value] = list()

            (value_to_indices_list_mapping_dict[value]).append(index)

        # Construct answer list.
        for current_index, value in enumerate(nums):
            # Compute total distance for current iterated element.
            total_distance = sum(
                abs(current_index - index)
                for index in value_to_indices_list_mapping_dict[value]
            )

            answer_list.append(total_distance)

        return answer_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 3, 1, 1, 2]],
        [[0, 5, 3]],
    ]

    for testcase in testcases_list:
        print(sol.distance(*testcase))
