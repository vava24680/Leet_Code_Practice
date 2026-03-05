from typing import List


class Solution:
    def maxProduct(self, words: List[str]) -> int:
        maximum_length = 0
        words_info_list = [None] * len(words)

        for index, current_word in enumerate(words):
            current_characters_bitmap = 0
            current_word_length = len(current_word)

            # Compute current word's characters' bitmap.
            for c in current_word:
                current_characters_bitmap |= (1 << (ord(c) - ord('a')))

            # Try current word with every word before it.
            for j in range(index):
                word_j_characters_mapping, word_j_length = words_info_list[j]

                if current_characters_bitmap & word_j_characters_mapping:
                    # Continue to next word current two words has common
                    # characters.
                    continue

                # Update maximum length if needed.
                maximum_length = max(
                    maximum_length,
                    current_word_length * word_j_length
                )

            words_info_list[index] = (
                current_characters_bitmap,
                current_word_length
            )

        return maximum_length


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [['abcw', 'baz', 'foo', 'bar', 'xtfn', 'abcdef']],
        [['a', 'ab', 'abc', 'd', 'cd', 'bcd', 'abcd']],
        [['a', 'aa', 'aaa', 'aaaa']],
    ]

    for testcase in testcases_list:
        print(sol.maxProduct(*testcase))
