from collections import Counter
from typing import List


class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        answer_list = list()
        values_counter = Counter()
        current_common_numbers_count = 0

        for num_1, num_2 in zip(A, B):
            (values_counter[num_1]) += 1

            if 2 == (values_counter[num_1]):
                # If a value's count is 2, it means it occurs in both of A list
                # and B list, we can increase common numbers count by 1.
                current_common_numbers_count += 1

            (values_counter[num_2]) += 1

            if 2 == (values_counter[num_2]):
                # If a value's count is 2, it means it occurs in both of A list
                # and B list, we can increase common numbers count by 1.
                current_common_numbers_count += 1

            answer_list.append(current_common_numbers_count)

        return answer_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 3, 2, 4], [3, 1, 2, 4]],
        [[2, 3, 1], [3, 1, 2]],
    ]

    for testcase in testcases_list:
        print(sol.findThePrefixCommonArray(*testcase))
