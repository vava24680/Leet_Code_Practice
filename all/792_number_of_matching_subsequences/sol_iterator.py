import string

from collections import deque
from typing import List


class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        subsequences_count = 0
        matching_strings_iterators_dict = {
            c: deque() for c in string.ascii_lowercase
        }

        # Add each word to rest strings dictionary based on their
        # first characters.
        for word in words:
            matching_string_iterator = iter(word)
            matching_strings_iterators_dict[
                next(matching_string_iterator)
            ].append(matching_string_iterator)

        for c in s:
            # Get how many strings are started with the current iterated
            # character.
            current_match_strings_count = len(
                matching_strings_iterators_dict[c]
            )

            # For those matched strings, advance their iterators for each
            # matched string.
            for _ in range(current_match_strings_count):
                matching_string_iterator = (
                    matching_strings_iterators_dict[c].popleft()
                )

                try:
                    # Advance iterator and add to corresponding queue.
                    matching_strings_iterators_dict[
                        next(matching_string_iterator)
                    ].append(
                        matching_string_iterator
                    )
                except StopIteration:
                    # If the iterator of a matched string is already at the end,
                    # it means we find a subsequence.
                    subsequences_count += 1

        return subsequences_count


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['ab', ['ab']],
        ['abcde', ['a', 'bb', 'acd', 'ace']],
        ['dsahjpjauf', ['ahjpjau', 'ja', 'ahbwzgqnuk', 'tnmlanowax']]
    ]

    for testcase in testcases_list:
        print(sol.numMatchingSubseq(*testcase))
