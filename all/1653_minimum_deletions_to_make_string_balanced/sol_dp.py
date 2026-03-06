class Solution:
    def minimumDeletions(self, s: str) -> int:
        dp_list = [0] * (len(s) + 1)
        previous_total_b_count = 0

        for index, c in enumerate(s):
            if 'b' == c:
                dp_list[index + 1] = dp_list[index]
                previous_total_b_count += 1
            elif 'a' == c:
                dp_list[index + 1] = min(
                    dp_list[index] + 1,
                    previous_total_b_count
                )

        return dp_list[len(s)]


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['aababbab'],
        ['bbaaaaabb'],
    ]

    for testcase in testcases_list:
        print(sol.minimumDeletions(*testcase))
