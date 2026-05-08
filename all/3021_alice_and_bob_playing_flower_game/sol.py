class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        # Find how many pairs of (x, y) such that they comply with the following
        # rules:
        # 1. 1 <= x <= n.
        # 2. 1 <= y <= m.
        # 3. x + y is odd.
        #
        # Since x + y must be odd, x and y cannot both be odd or even, x is even
        # and y is odd, or either x is odd and y is even.
        #
        # For a positive integer i:
        # 1. The number of even numbers that are equal to itself or less than it
        #    is (i / 2).
        # 2. The number of odd numbers that are equal to itself or less than it
        #    is ((i + 1)/ 2).
        #
        # We can use the observations above to compute how many pairs of (x, y).

        return (
            ((n >> 1) * ((m + 1) >> 1))
            +
            (((n + 1) >> 1) * (m >> 1))
        )


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [3, 2],
        [1, 1],
    ]

    for testcase in testcases_list:
        print(sol.flowerGame(*testcase))
