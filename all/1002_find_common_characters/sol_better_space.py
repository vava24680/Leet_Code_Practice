from collections import Counter
from typing import List


class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        if not words:
            return list()

        answer_list = []

        # Compute each letter's count in the first given word and store result
        # in the letters minimum counter.
        letters_minimum_count_counter = Counter(words[0])

        for word_index in range(1, len(words)):
            # Compute each letter's count in the iterated word and use inplace
            # intersection operation to update each letter's minimum count.
            letters_minimum_count_counter &= (Counter(words[word_index]))

        for letter, minimum_count in letters_minimum_count_counter.items():
            # Iterate each letter and its minimum count.

            if 0 == minimum_count:
                # If a letter's minimum count is 0, which means it does show
                # in any of given words at all, just skip it.
                continue

            answer_list.extend([letter] * minimum_count)

        return answer_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [['bella', 'label', 'roller']],
        [['cool', 'lock', 'cook']],
    ]

    for testcase in testcases_list:
        print(sol.commonChars(*testcase))
