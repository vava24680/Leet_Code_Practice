import string

from collections import deque
from typing import List


class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        subsequences_count = 0
        rest_strings_dict = {c: deque(list()) for c in string.ascii_lowercase}

        # Add each word to rest strings dictionary based on their
        # first characters.
        for word in words:
            rest_strings_dict[word[0]].append((word, 0))

        for c in s:
            # Get how many strings are started with the current iterated
            # character.
            current_match_strings_count = len(rest_strings_dict[c])

            # For those matched strings, advance their indices for each matched
            # string.
            for _ in range(current_match_strings_count):
                word, current_index = rest_strings_dict[c].popleft()

                if (len(word) - 1) == current_index:
                    # If the index of a matched string is already at the end,
                    # it means we find a subsequence.
                    subsequences_count += 1
                else:
                    # Advance index and add to corresponding queue.
                    rest_strings_dict[word[current_index + 1]].append(
                        (word, current_index + 1)
                    )

        return subsequences_count


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['abcde', ['a', 'bb', 'acd', 'ace']],
        ['dsahjpjauf', ['ahjpjau', 'ja', 'ahbwzgqnuk', 'tnmlanowax']]
    ]

    for testcase in testcases_list:
        print(sol.numMatchingSubseq(*testcase))
