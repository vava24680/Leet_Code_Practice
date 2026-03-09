class Solution:
    def romanToInt(self, s: str) -> int:
        ROMAN_CHARS_TO_INT_MAP = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000,
        }
        result = 0
        previous_roman_char = '0'

        for i in range(len(s)):
            result += ROMAN_CHARS_TO_INT_MAP.get(s[i], 0)

            if (('V' == s[i]) or ('X' == s[i])) and ('I' == previous_roman_char):
                result -= 2
            elif (('L' == s[i]) or ('C' == s[i])) and ('X' == previous_roman_char):
                result -= 20
            elif (('D' == s[i]) or ('M' == s[i])) and ('C' == previous_roman_char):
                result -= 200

            previous_roman_char = s[i]

        return result


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['III'],
        ['LVIII'],
        ['MCMXCIV'],
    ]

    for testcase in testcases_list:
        print(sol.romanToInt(*testcase))
