import string

from collections import Counter, deque
from typing import List


class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        subsequences_count = 0
        unique_strings_counter = Counter(words)
        matching_strings_iterators_dict = {
            c: deque() for c in string.ascii_lowercase
        }

        # Add each unique word to rest strings dictionary based on their
        # first characters.
        for word, count in unique_strings_counter.items():
            matching_string_iterator = iter(word)
            matching_strings_iterators_dict[
                next(matching_string_iterator)
            ].append((matching_string_iterator, count))

        for c in s:
            # Get how many strings are started with the current iterated
            # character.
            current_match_strings_count = len(
                matching_strings_iterators_dict[c]
            )

            # For those matched strings, advance their iterators for each
            # matched string.
            for _ in range(current_match_strings_count):
                matching_string_iterator, count = (
                    matching_strings_iterators_dict[c].popleft()
                )

                try:
                    # Advance iterator and add to corresponding queue.
                    matching_strings_iterators_dict[
                        next(matching_string_iterator)
                    ].append(
                        (matching_string_iterator, count)
                    )
                except StopIteration:
                    # If the iterator of a matched string is already at the end,
                    # it means we find a subsequence.
                    subsequences_count += count

        return subsequences_count


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        (3, ['abcde', ['a', 'bb', 'acd', 'ace']]),
        (2, ['dsahjpjauf', ['ahjpjau', 'ja', 'ahbwzgqnuk', 'tnmlanowax']]),
        (2, ['dsahjpjauf', ['ahjpjau', 'ja', 'ahbwzgqnuk', 'tnmlanowax']]),
    ]

    for expected_answer, testcase in testcases_list:
        my_answer = sol.numMatchingSubseq(*testcase)

        print(my_answer)

        assert expected_answer == my_answer, f'Expected: {expected_answer}, actual: {my_answer}'

    print('Success')
