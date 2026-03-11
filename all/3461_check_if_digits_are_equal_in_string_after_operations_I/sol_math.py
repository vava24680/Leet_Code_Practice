class Solution:
    def hasSameDigits(self, s: str) -> bool:
        s_length = len(s)
        current_bionomial_coefficient = 1
        first_digit, second_digit = 0, 0

        for i in range(len(s) - 1):
            first_digit = (
                (first_digit + (current_bionomial_coefficient * int(s[i])))
                %
                10
            )
            second_digit = (
                (second_digit + (current_bionomial_coefficient * int(s[i + 1])))
                %
                10
            )

            current_bionomial_coefficient = (
                current_bionomial_coefficient * ((s_length - 2) - i) // (i + 1)
            )

            # After computing new binomial coefficient, we cannot take its
            # remainder by modulo by 10 as equivalent new binomial coefficient
            # since congruence does not support division generally.

        return first_digit == second_digit


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['3902'],
        ['34789'],
    ]

    for testcase in testcases_list:
        print(sol.hasSameDigits(*testcase))
