class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        # As the starting character of s is 1, we just need to check if there
        # has '01' in s that will start second continuous segment of ones.
        return '01' not in s


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['1001'],
        ['110'],
        ['1'],
    ]

    for testcase in testcases_list:
        print(sol.checkOnesSegment(*testcase))
