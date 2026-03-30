import string


LOWERCASE_LETTERS_COUNT = 26


class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        # The characters count difference list at index 0 is for the characters
        # positioned at the even index.
        # The characters count difference list at index 1 is for the characters
        # positioned at the odd index.
        characters_count_difference_list = [
            {c: 0 for c in string.ascii_lowercase},
            {c: 0 for c in string.ascii_lowercase},
        ]

        for index, c in enumerate(s1):
            characters_count_difference_list[index & 0x1][c] += 1

        for index, c in enumerate(s2):
            # Return false if the count difference of a character is already 0,
            # it means that character at the even positions or odd positions
            # shows more times than in the string s1.
            if 0 == (characters_count_difference_list[index & 0x1][c]):
                return False

            characters_count_difference_list[index & 0x1][c] -= 1

        # If programe is here, it means that the characters at the even
        # positions (odd positions) in the string s1 has the same count
        # as the characters at the even positions (odd positions) in the
        # string s2.
        return True


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['abcdba', 'cabdab'],
        ['abe', 'bea'],
    ]

    for testcase in testcases_list:
        print(sol.checkStrings(*testcase))
