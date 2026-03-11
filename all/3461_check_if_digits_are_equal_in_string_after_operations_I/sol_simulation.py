class Solution:
    def hasSameDigits(self, s: str) -> bool:
        digits_list = [int(c) for c in s]
        current_valid_digits_count = len(digits_list)

        while current_valid_digits_count > 2:
            for i in range(current_valid_digits_count - 1):
                digits_list[i] = (digits_list[i] + digits_list[i + 1]) % 10

            current_valid_digits_count -= 1

        return digits_list[0] == digits_list[1]


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['3902'],
        ['34789'],
    ]

    for testcase in testcases_list:
        print(sol.hasSameDigits(*testcase))
