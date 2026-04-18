class Solution:
    def mirrorDistance(self, n: int) -> int:
        return abs(n - int(str(n)[::-1]))


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [25],
        [10],
        [7],
    ]

    for testcase in testcases_list:
        print(sol.mirrorDistance(*testcase))
