class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        s_length = len(s)

        if s_length != len(goal):
            return False

        for start_index in range(s_length):
            for i in range(s_length):
                if (goal[i]) != (s[(i + start_index) % s_length]):
                    break
            else:
                return True

        return False


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['abcde', 'cdeab'],
        ['abcde', 'abced'],
    ]

    for testcase in testcases_list:
        print(sol.rotateString(*testcase))
