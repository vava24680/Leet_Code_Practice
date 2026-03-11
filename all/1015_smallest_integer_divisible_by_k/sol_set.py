class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if 0 == (k & 0x1):
            # As n is a all 1-digit number, an odd number n cannot be factor
            # of an even number k, just return -1 directly.
            return -1

        remainders_set = set()
        current_n_length = 0
        current_n_remainder = 0

        while True:
            current_n_length += 1
            # Use congruence modulo compute the remainder of current n modulo
            # by k by using the remainder of the previous n modulo by k.
            current_n_remainder = ((current_n_remainder * 10) + 1) % k

            if current_n_remainder in remainders_set:
                # If remainder of current n modulo by k has been in remainders'
                # set, it means remainder has circled back and form a loop,
                # it is impossible to find a number n with all digit 1 that is
                # a multiple of k, so just return -1.
                return -1

            # Add current remainder to remainders' set.
            remainders_set.add(current_n_remainder)

            if 0 == current_n_remainder:
                break

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
