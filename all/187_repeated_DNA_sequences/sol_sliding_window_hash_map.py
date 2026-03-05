from typing import List


class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        found_dns_sequences_set = set()
        added_dns_sequences_set = set()

        for i in range(len(s) - 10 + 1):
            current_dna_sequence = s[i:i + 10]

            if current_dna_sequence not in found_dns_sequences_set:
                found_dns_sequences_set.add(current_dna_sequence)
            elif current_dna_sequence not in added_dns_sequences_set:
                added_dns_sequences_set.add(current_dna_sequence)

        return list(added_dns_sequences_set)


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT'],
        ['AAAAAAAAAAAAA'],
    ]

    for testcase in testcases_list:
        print(sol.findRepeatedDnaSequences(*testcase))
