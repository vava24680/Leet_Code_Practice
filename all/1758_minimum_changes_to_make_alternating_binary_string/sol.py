class Solution:
    def minOperations(self, s: str) -> int:
        # For starting bit is 1 case.
        current_expected_bit_1 = 1
        operations_count_1 = 0

        # For starting bit is 0 case.
        current_expected_bit_2 = 0
        operations_count_2 = 0

        for c in s:
            if int(c) != current_expected_bit_1:
                operations_count_1 += 1

            if int(c) != current_expected_bit_2:
                operations_count_2 += 1

            current_expected_bit_1 ^= 1
            current_expected_bit_2 ^= 1

        return min(operations_count_1, operations_count_2)


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['0100'],
        ['10'],
        ['1111'],
        ['1011010101'],
    ]

    for testcase in testcases_list:
        print(sol.minOperations(*testcase))
