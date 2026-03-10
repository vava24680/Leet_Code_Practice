from collections import Counter
from typing import List


class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        words_counter_in_s1 = Counter(s1.split())
        words_counter_in_s2 = Counter(s2.split())
        result_list = []

        for word, count in words_counter_in_s1.items():
            if (1 == count) and (word not in words_counter_in_s2):
                result_list.append(word)

        for word, count in words_counter_in_s2.items():
            if (1 == count) and (word not in words_counter_in_s1):
                result_list.append(word)

        return result_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['this apple is sweet', 'this apple is sour'],
        ['apple apple', 'banana'],
    ]

    for testcase in testcases_list:
        print(sol.uncommonFromSentences(*testcase))
