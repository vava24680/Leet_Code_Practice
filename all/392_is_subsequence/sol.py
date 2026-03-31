class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        s_length, t_length = len(s), len(t)
        s_idx = t_idx = 0

        while (s_length != s_idx) and (t_length != t_idx):
            if s[s_idx] == t[t_idx]:
                s_idx += 1
                t_idx += 1
            else:
                t_idx += 1

        return s_idx == s_length


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['abc', 'ahbgdc'],
        ['axc', 'ahbgdc'],
    ]

    for testcase in testcases_list:
        print(sol.isSubsequence(*testcase))
