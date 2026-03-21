class Solution:
    VOWEL_CHARACTERS = 'aeiouAEIOU'

    def reverseVowels(self, s: str) -> str:
        # We can collect all vowel characters from s to s stack.
        # Iterate s again:
        # 1. If current character is not a vowel, do no thing.
        # 2. If current character is a vowel, pop one character from that
        #    stack and change current character with the one poped from
        #    stack.
        # After all iterations, all vowel characters in s are reversed.
        # The reason why this is works is because that reverse a list is
        # basically swap the first element and the last element and then
        # swap the second element and the second to last element and so
        # on so forth. Stack's LIFO feature is perfectly suitable for
        # this kind of pairing order.
        #
        # Ref: Leetcode code sample.
        vowel_characters_list = [c for c in s if c in self.VOWEL_CHARACTERS]
        answer_list = [
            vowel_characters_list.pop() if c in self.VOWEL_CHARACTERS else c
            for c in s
        ]

        return ''.join(answer_list)


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['IceCreAm'],
        ['leetcode'],
    ]

    for testcase in testcases_list:
        print(sol.reverseVowels(*testcase))
