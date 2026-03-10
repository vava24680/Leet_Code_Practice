import itertools

from collections import Counter
from typing import List


class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        # Use itertools.chain to chain the result of splitting of s1 and s2
        # is to prevent create large temporary list.
        words_counter = Counter(itertools.chain(s1.split(), s2.split()))

        # Return all the words that only show one time in the combination
        # of s1 and s2.
        return [word for word, count in words_counter.items() if 1 == count]


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['this apple is sweet', 'this apple is sour'],
        ['apple apple', 'banana'],
    ]

    for testcase in testcases_list:
        print(sol.uncommonFromSentences(*testcase))
