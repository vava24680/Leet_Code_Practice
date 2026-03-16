import math


class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        gcd_of_both_strings_lengths = math.gcd(len(str1), len(str2))
        possible_maximum_common_divisor_string = (
            str1[:gcd_of_both_strings_lengths]
        )

        if (
            (
                str1
                !=
                (
                    possible_maximum_common_divisor_string
                    *
                    (len(str1) // gcd_of_both_strings_lengths)
                )
            )
            or
            (
                str2
                !=
                (
                    possible_maximum_common_divisor_string
                    *
                    (len(str2) // gcd_of_both_strings_lengths)
                )
            )
        ):
            return ''

        return possible_maximum_common_divisor_string


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['ABCABC', 'ABC'],
        ['ABABAB', 'AB'],
        ['LEET', 'CODE'],
        ['AAAAAB', 'AAA'],
    ]

    for testcase in testcases_list:
        print(sol.gcdOfStrings(*testcase))
