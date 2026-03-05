MODULO_NUMBER = 1000000007


class Solution:
    def concatenatedBinary(self, n: int) -> int:
        answer = 0
        left_shift_bits_count = 0

        for i in range(1, n + 1):
            if 0 == (i & (i - 1)):
                # If current number is power of 2, we need to increase left
                # shift bits count by 1 to get correct left shift bits count.
                left_shift_bits_count += 1

            # Treat concatenation as the original number is left shifted by
            # some bits and do a addition later.
            answer = ((answer << left_shift_bits_count) + i)

        return answer % MODULO_NUMBER


if '__main__' == __name__:
    sol = Solution()

    testcases_list = [
        [1],
        [3],
        [12],
    ]

    for testcase in testcases_list:
        print(sol.concatenatedBinary(*testcase))
