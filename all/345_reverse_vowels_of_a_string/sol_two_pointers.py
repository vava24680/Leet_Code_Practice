class Solution:
    VOWEL_CHARACTERS_SET = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}

    def reverseVowels(self, s: str) -> str:
        s_length = len(s)
        list_s = list(s)
        left_index, right_index = 0, s_length - 1

        while True:
            while (
                (left_index < right_index)
                and
                (s[left_index] not in self.VOWEL_CHARACTERS_SET)
            ):
                # Find the next vowel character from left.
                left_index += 1

            while (
                (right_index > left_index)
                and
                (s[right_index] not in self.VOWEL_CHARACTERS_SET)
            ):
                # Find the next vowel character from right.
                right_index -= 1

            if left_index >= right_index:
                # Break if the left index is equal or greater than the right
                # index.
                # When this happens, it means all vowel characters have been
                # reversed.
                break

            # Swap the vowels characters indexed by the left index and the right
            # index.
            list_s[left_index], list_s[right_index] = (
                list_s[right_index], list_s[left_index]
            )

            # Update the left index and the right index.
            left_index += 1
            right_index -= 1

        return ''.join(list_s)


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['IceCreAm'],
        ['leetcode'],
    ]

    for testcase in testcases_list:
        print(sol.reverseVowels(*testcase))
