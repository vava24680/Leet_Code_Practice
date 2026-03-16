from typing import List


class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        domino_values_counter_list = [0] * 100
        result_pairs_count = 0

        # Compute each domino value and their count.
        for a, b in dominoes:
            domino_values_counter_list[(a * 10) + b] += 1

        # After computing each domino value and their counts, we can iterate
        # each domino and use that counts information to find how many domino
        # in the rest of dominoes are considered equivalent as the current
        # iterated one.
        #
        # This can save us unnecessary loop checking.
        for a, b in dominoes:
            domino_value = ((a * 10) + b)
            rotated_domino_value = ((b * 10) + a)

            # This decrease by 1 is used to skip the current iterated domino
            # itself.
            domino_values_counter_list[domino_value] -= 1

            result_pairs_count += domino_values_counter_list[domino_value]

            # If the value of a domino is as same as the value of a rotated
            # one, we must skip finding for equivalent rotated dominoes or
            # we will count repeatedly.
            if domino_value != rotated_domino_value:
                result_pairs_count += (
                    domino_values_counter_list[rotated_domino_value]
                )

        return result_pairs_count


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[[1, 2], [2, 1], [3, 4], [5, 6]]],
        [[[1, 2], [1, 2], [1, 1], [1, 2], [2, 2]]],
    ]

    for testcase in testcases_list:
        print(sol.numEquivDominoPairs(*testcase))
