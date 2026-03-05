class Solution:
    def numSteps(self, s: str) -> int:
        steps_count = 0
        carry_value = 0

        for i in reversed(range(1, len(s))):
            # Compute current LSB actual value by adding its original value with
            # carry value.
            if 1 == (carry_value + int(s[i])):
                steps_count += 2
                carry_value = 1
            else:
                steps_count += 1

                if carry_value and ('1' == s[i]):
                    carry_value = 1
                else:
                    carry_value = 0

        # MSB must be 1, and if carry value is still 1, we need to do one more
        # operation to make 1 to 1.
        return steps_count + carry_value


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['1101'],
        ['10'],
        ['1'],
    ]

    for testcase in testcases_list:
        print(sol.numSteps(*testcase))
