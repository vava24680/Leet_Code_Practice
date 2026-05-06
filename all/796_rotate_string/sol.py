class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        s_length = len(s)

        if s_length != len(goal):
            return False

        for base_index in range(s_length):
            if (
                (s[base_index:] == goal[:s_length - base_index])
                and
                (s[:base_index] == goal[s_length - base_index:])
            ):
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
