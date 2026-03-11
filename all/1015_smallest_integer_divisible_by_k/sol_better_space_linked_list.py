class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if 0 == (k & 0x1):
            # As n is a all 1-digit number, an odd number n cannot be factor
            # of an even number k, just return -1 directly.
            return -1

        current_n_length = 0
        slow_remainder = 0
        fast_remainder = 0

        while True:
            current_n_length += 1

            slow_remainder = ((slow_remainder * 10) + 1) % k
            fast_remainder = ((fast_remainder * 10) + 1) % k
            fast_remainder = ((fast_remainder * 10) + 1) % k

            if 0 == slow_remainder:
                break

            if slow_remainder == fast_remainder:
                # If slow remainder and fast remainder are the same and the slow
                # remainder is greater than 0, it means remainder has circled
                # back and form a loop. It is impossible that there is n with
                # all digit 1 and that n is a multiple of k, so just return -1.
                return -1

        return current_n_length


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [1],
        [2],
        [3],
    ]

    for testcase in testcases_list:
        print(sol.smallestRepunitDivByK(*testcase))
