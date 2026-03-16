import math


class Solution:
    def isStringDivisible(self, target_string: str, divisor_string: str) -> bool:
        divisor_string_length = len(divisor_string)
        i = 0

        for c in target_string:
            if divisor_string_length == i:
                i = 0

            if c != divisor_string[i]:
                return False

            i += 1

        return i == divisor_string_length

    def gcdOfStrings(self, str1: str, str2: str) -> str:
        gcd_of_both_strings_lengths = math.gcd(len(str1), len(str2))
        possible_maximum_common_divisor_string = (
            str1[:gcd_of_both_strings_lengths]
        )

        if (
            (not self.isStringDivisible(str1, possible_maximum_common_divisor_string))
            or
            (not self.isStringDivisible(str2, possible_maximum_common_divisor_string))
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
