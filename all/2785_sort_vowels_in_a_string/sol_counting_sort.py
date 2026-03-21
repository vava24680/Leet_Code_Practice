NON_DECREASING_VOWEL_CHARACTERS_STRING = 'AEIOUaeiou'
VOWEL_CHARACTERS_SET = set(NON_DECREASING_VOWEL_CHARACTERS_STRING)


class Solution:
    def sortVowels(self, s: str) -> str:
        result_characters_list = list(s)
        vowel_character_count_dict = {vowel: 0 for vowel in 'AEIOUaeiou'}

        for c in s:
            if c not in VOWEL_CHARACTERS_SET:
                continue

            vowel_character_count_dict[c] += 1

        i = 0

        current_vowel_character_index = 0

        for i in range(len(result_characters_list)):
            if (result_characters_list[i]) not in VOWEL_CHARACTERS_SET:
                continue

            while (
                0
                ==
                (
                    vowel_character_count_dict[
                        NON_DECREASING_VOWEL_CHARACTERS_STRING[
                            current_vowel_character_index
                        ]
                    ]
                )
            ):
                current_vowel_character_index += 1

            current_vowel_character = (
                NON_DECREASING_VOWEL_CHARACTERS_STRING[
                    current_vowel_character_index
                ]
            )

            result_characters_list[i] = current_vowel_character
            (vowel_character_count_dict[current_vowel_character]) -= 1

        return ''.join(result_characters_list)


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['lEetcOde'],
        ['lYmpH'],
    ]

    for testcase in testcases_list:
        print(sol.sortVowels(*testcase))
