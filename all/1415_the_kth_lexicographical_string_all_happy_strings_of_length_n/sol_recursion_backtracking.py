from typing import List


PREVIOUS_CHARACTERS_AND_AVAILABLE_CHARACTERS_MAPPING = {
    'a': ['b', 'c'],
    'b': ['a', 'c'],
    'c': ['a', 'b'],
}


class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        total_happy_strings_count = 3 * (1 << (n - 1))

        if (n < 1) or (k > total_happy_strings_count):
            return ''

        happy_strings_characters_list = list()

        def generateAllHappyStrings(
            candidate_characters: List[str],
            current_happy_string_characters_list: List[str]
        ) -> None:
            nonlocal happy_strings_characters_list

            if n == len(current_happy_string_characters_list):
                happy_strings_characters_list.append(
                    current_happy_string_characters_list.copy()
                )

                return

            for candidate_character in candidate_characters:
                current_happy_string_characters_list.append(candidate_character)
                generateAllHappyStrings(
                    PREVIOUS_CHARACTERS_AND_AVAILABLE_CHARACTERS_MAPPING[
                        candidate_character
                    ],
                    current_happy_string_characters_list
                )
                current_happy_string_characters_list.pop()

        generateAllHappyStrings(['a', 'b', 'c'], list())

        return ''.join(happy_strings_characters_list[k - 1])


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [1, 3],
        [1, 4],
        [3, 9],
        [4, 16],
    ]

    for testcase in testcases_list:
        print(sol.getHappyString(*testcase))
