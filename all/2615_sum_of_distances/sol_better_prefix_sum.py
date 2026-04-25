from typing import List


class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        answer_list = [0] * len(nums)
        value_to_indices_list_mapping_dict = dict()

        # Construct value to indices list mapping.
        for index, value in enumerate(nums):
            if value not in value_to_indices_list_mapping_dict:
                value_to_indices_list_mapping_dict[value] = list()

            (value_to_indices_list_mapping_dict[value]).append(index)

        for value, indices_list in value_to_indices_list_mapping_dict.items():
            # For each index in a indices list, we leverage prefix sum and
            # suffix sum to compute total distance for that index.
            #
            # Please check notes for detailed explanation.
            indices_list_length = len(indices_list)
            total_distance_from_head = 0
            total_distance_from_tail = 0

            for i in range(1, indices_list_length):
                # Leverage prefix sum to compute total distance between current
                # index and all indices before it.
                distance_between_current_index_and_previous_index = (
                    (indices_list[i]) - (indices_list[i - 1])
                )
                total_distance_from_head = (
                    total_distance_from_head
                    +
                    (distance_between_current_index_and_previous_index * i)
                )

                # Accumulate current computed total distance from head to the
                # corresponding slot in the answer list for the current iterated
                # index.
                answer_list[indices_list[i]] += total_distance_from_head

            for i in reversed(range(indices_list_length - 1)):
                # Leverage suffix sum to compute total distance between current
                # index and all indices after it.
                distance_between_current_index_and_next_index = (
                    (indices_list[i + 1]) - (indices_list[i])
                )

                total_distance_from_tail = (
                    total_distance_from_tail
                    +
                    (
                        distance_between_current_index_and_next_index
                        *
                        (indices_list_length - 1 - i)
                    )
                )

                # Accumulate current computed total distance from tail to the
                # corresponding slot in the answer list for the current iterated
                # index.
                answer_list[indices_list[i]] += total_distance_from_tail

        return answer_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 3, 1, 1, 2]],
        [[0, 5, 3]],
    ]

    for testcase in testcases_list:
        print(sol.distance(*testcase))
