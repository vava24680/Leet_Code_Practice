from typing import List


CHARACTER_ENDCODING_DICT = {
    'A': 0x0,
    'C': 0x1,
    'T': 0x2,
    'G': 0x3,
}

DNA_SEQUENCE_ENCODING_BITMASK = ((1 << 20) - 1)


class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        answer_list = list()
        found_dns_sequences_encoding_set = set()
        added_dns_sequences_encoding_set = set()
        current_dns_sequence_encoding = 0
        window_left_index = 0

        for window_right_index in range(len(s)):
            # Add new character encoding and mask the unused encoding.
            current_dns_sequence_encoding <<= 2
            current_dns_sequence_encoding |= (
                CHARACTER_ENDCODING_DICT[s[window_right_index]]
            )
            current_dns_sequence_encoding &= DNA_SEQUENCE_ENCODING_BITMASK

            if (window_right_index - window_left_index + 1) < 10:
                # Contine to span the current window if current window does
                # not cover 10 characters yet.
                continue

            if current_dns_sequence_encoding not in (
                found_dns_sequences_encoding_set
            ):
                # Add current DNA sequence encoding to found DNA sequences
                # encoding set if current DNA sequence encoding does not show
                # in that set.
                found_dns_sequences_encoding_set.add(
                    current_dns_sequence_encoding
                )
            elif current_dns_sequence_encoding not in (
                added_dns_sequences_encoding_set
            ):
                # Add current DNA sequence encoding to added DNS sequences
                # encoding set if current DNA sequence encoding does not
                # show in that set.
                # Also need to add current DNA sequence to answer list.
                added_dns_sequences_encoding_set.add(
                    current_dns_sequence_encoding
                )
                answer_list.append(
                    s[window_left_index:window_right_index + 1]
                )

            window_left_index += 1

        return answer_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT'],
        ['AAAAAAAAAAAAA'],
    ]

    for testcase in testcases_list:
        print(sol.findRepeatedDnaSequences(*testcase))
