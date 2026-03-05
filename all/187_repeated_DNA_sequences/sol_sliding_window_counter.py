from collections import Counter
from typing import List


class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        # Record each DNS sequence's count.
        dna_sequences_counter = Counter(
            s[i:i + 10] for i in range(len(s) - 10 + 1)
        )

        # Only get those DNS sequences whose counts are greater than 1.
        return [
            string
            for string, count in dna_sequences_counter.items() if count > 1
        ]


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT'],
        ['AAAAAAAAAAAAA'],
    ]

    for testcase in testcases_list:
        print(sol.findRepeatedDnaSequences(*testcase))
