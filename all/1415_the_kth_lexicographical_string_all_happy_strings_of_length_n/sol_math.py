PREVIOUS_CHARACTERS_AND_AVAILABLE_CHARACTERS_MAPPING = {
    'a': ['b', 'c'],
    'b': ['a', 'c'],
    'c': ['a', 'b'],
}

class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        total_happy_strings_count = 3 * (1 << (n - 1))

        if k > total_happy_strings_count:
            return ''

        happy_strings_count_in_a_group = (total_happy_strings_count // 3)
        happy_string_current_index, happy_string_new_index = divmod(
            k - 1,
            happy_strings_count_in_a_group
        )
        answer_happy_string_characters_list = [
            chr(ord('a') + happy_string_current_index)
        ]
        happy_strings_count_in_a_group >>= 1

        while happy_strings_count_in_a_group:
            happy_string_current_index, happy_string_new_index = divmod(
                happy_string_new_index,
                happy_strings_count_in_a_group
            )
            answer_happy_string_characters_list.append(
                PREVIOUS_CHARACTERS_AND_AVAILABLE_CHARACTERS_MAPPING[
                    answer_happy_string_characters_list[-1]
                ][
                    happy_string_current_index
                ]
            )

            happy_strings_count_in_a_group >>= 1

        return ''.join(answer_happy_string_characters_list)


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
