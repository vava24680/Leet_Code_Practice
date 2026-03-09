from typing import List


class Solution:
    def countBits(self, n: int) -> List[int]:
        # Number n | Binary                 | Number of bit value 1
        #          | representation (4-bit) |
        # ---------|------------------------|----------------------
        #      0   | 0000                   | 0
        #      1   | 0001                   | 1
        #      2   | 0010                   | 1
        #      3   | 0011                   | 2
        #      4   | 0100                   | 1
        #      5   | 0101                   | 2
        #      6   | 0110                   | 2
        #      7   | 0111                   | 3
        #      8   | 1000                   | 1
        #      9   | 1001                   | 2
        #     10   | 1010                   | 2
        #     11   | 1011                   | 3
        #     12   | 1100                   | 2
        #     13   | 1101                   | 3
        #     14   | 1110                   | 3
        #     15   | 1111                   | 4
        #
        # By some observations, we can conclude the following rules:
        # 1. If n is 0, number of bit value 1 is 0. "This is base case".
        # 2. If n is odd, number of bit value 1 is 1 plus the result of (n - 1).
        #    This is trivial proven by the n is a result of (n - 1) + 1,
        #    and (n - 1) is even so the bit 0's value must be 0, plus 1 won't
        #    cause carry, so the number of bit value 1 in n is one more than
        #    (n - 1).
        # 3. If n is even, number of bit value 1 is the result of
        #    ((n - 1) / 2 + 1).
        #    This can also be proven by the n is a result of (n - 1) + 1,
        #    and (n - 1) is odd so the bit 0's value must be 1, plus 1 will
        #    cause carry, if we ignore bit 0, the rest of addtion will be
        #    ((n - 1) / 2) + 1, so the number of bit value 1 in n is the number
        #    of bit value 1 in ((n - 1) / 2 + 1).
        #
        # This is a typical dynamic programming problem.
        result = [0] * (n + 1)

        for i in range(1, n + 1):
            if i & 0x1:
                result[i] = result[i - 1] + 1
            else:
                result[i] = result[((i - 1) >> 1) + 1]

        return result


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [2],
        [5],
    ]

    for testcase in testcases_list:
        print(sol.countBits(*testcase))
