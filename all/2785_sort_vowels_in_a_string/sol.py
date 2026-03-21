VOWEL_CHARACTERS_SET = set('aeiouAEIOU')


class Solution:
    def sortVowels(self, s: str) -> str:
        result_characters_list = list(s)
        vowels_list = [c for c in s if c in VOWEL_CHARACTERS_SET]

        vowels_list.sort()
        vowels_iterator = iter(vowels_list)

        for i in range(len(result_characters_list)):
            if result_characters_list[i] not in VOWEL_CHARACTERS_SET:
                continue

            result_characters_list[i] = next(vowels_iterator)

        return ''.join(result_characters_list)


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['lEetcOde'],
        ['lYmpH'],
    ]

    for testcase in testcases_list:
        print(sol.sortVowels(*testcase))
