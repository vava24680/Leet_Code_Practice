class Solution:
    def divisorGame(self, n: int) -> bool:
        return 0 == (n & 0x1)


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [2],
        [3],
        [4],
    ]

    for testcase in testcases_list:
        print(sol.divisorGame(*testcase))
