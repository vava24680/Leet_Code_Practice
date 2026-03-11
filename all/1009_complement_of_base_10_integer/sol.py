class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if 0 == n:
            return 1

        n_bit_length = 0
        process_num = n

        while process_num:
            n_bit_length += 1
            process_num >>= 1

        return n ^ ((1 << n_bit_length) - 1)


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [5],
        [7],
        [10],
    ]

    for testcase in testcases_list:
        print(sol.bitwiseComplement(*testcase))
