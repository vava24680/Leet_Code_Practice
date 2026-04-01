import string

from collections import Counter, deque
from typing import List


class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        subsequences_count = 0
        unique_strings_counter = Counter(words)
        rest_strings_dict = {c: deque(list()) for c in string.ascii_lowercase}

        # Add each unique word to rest strings dictionary based on their
        # first characters.
        for word in unique_strings_counter.keys():
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
                    subsequences_count += unique_strings_counter[word]
                else:
                    # Advance index and add to corresponding queue.
                    rest_strings_dict[word[current_index + 1]].append(
                        (word, current_index + 1)
                    )

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
