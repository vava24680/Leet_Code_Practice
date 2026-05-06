class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False

        return goal in (s + s)


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['abcde', 'cdeab'],
        ['abcde', 'abced'],
    ]

    for testcase in testcases_list:
        print(sol.rotateString(*testcase))
