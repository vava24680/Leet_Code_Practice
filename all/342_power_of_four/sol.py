class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        # This Python solution only works if n is a number that can be
        # represented in signed 32-bit number.
        if (n <= 0) or (0 != (n & (n - 1))):
            return False

        return 0 == (n & (~0x55555555))


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [16],
        [5],
        [1],
    ]

    for testcase in testcases_list:
        print(sol.isPowerOfFour(*testcase))
