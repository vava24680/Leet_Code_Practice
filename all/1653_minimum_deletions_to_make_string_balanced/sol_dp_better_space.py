class Solution:
    def minimumDeletions(self, s: str) -> int:
        current_dp_state = 0
        previous_total_b_count = 0

        for index, c in enumerate(s):
            if 'b' == c:
                previous_total_b_count += 1
            elif 'a' == c:
                current_dp_state = min(
                    current_dp_state + 1,
                    previous_total_b_count
                )

        return current_dp_state


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['aababbab'],
        ['bbaaaaabb'],
    ]

    for testcase in testcases_list:
        print(sol.minimumDeletions(*testcase))
