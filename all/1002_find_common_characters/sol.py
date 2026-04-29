from collections import Counter
from string import ascii_lowercase
from typing import List


class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        answer_list = list()
        letters_counters_list = list()

        for word in words:
            # Compute each letter's count in a iterated word and store result
            # in a counters list.
            letters_counters_list.append(Counter(word))

        for letter in ascii_lowercase:
            # Find the minimum count of each letter.
            minimum_count = float('inf')

            for letters_counter in letters_counters_list:
                minimum_count = min(
                    minimum_count,
                    letters_counter[letter]
                )

            if float('inf') == minimum_count:
                # If a letter's minimum count is infinite value, which means
                # that this letter does not show in the given words at all,
                # so we can continue to next letter.
                continue

            # Add letters to answer list.
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
