class Solution:
    def minimumDeletions(self, s: str) -> int:
        # Count how many a in the string s first.
        total_a_count = sum('a' == c for c in s)
        previous_total_a_count = 0
        previous_total_b_count = 0
        minimum_deletions_count = len(s) + 1

        # Try every cut index, from 0 to string s length.
        #
        # For every cut index i, the string is splitted into parts: s[:i] and
        # s[i:].
        # We need to remove all the character b in the s[:i] and remove all the
        # character a in the s[i:] to make the string s balanced under current
        # cutting.
        #
        # To compute the count of the character a in the s[i:], it is the
        # difference of the count of the character a in the string s minus
        # the count of the charactera in the s[:i], so we can use prefix sum
        # to avoid repreated counting.
        for cut_index in range(len(s)):
            minimum_deletions_count = min(
                minimum_deletions_count,
                (
                    previous_total_b_count
                    +
                    (total_a_count - previous_total_a_count)
                )
            )

            if 'b' == s[cut_index]:
                previous_total_b_count += 1
            elif 'a' == s[cut_index]:
                previous_total_a_count += 1

        # The last cut index is len(s).
        minimum_deletions_count = min(
            minimum_deletions_count,
            previous_total_b_count + (total_a_count - previous_total_a_count)
        )

        return minimum_deletions_count


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['aababbab'],
        ['bbaaaaabb'],
    ]

    for testcase in testcases_list:
        print(sol.minimumDeletions(*testcase))
