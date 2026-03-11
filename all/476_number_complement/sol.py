class Solution:
    def findComplement(self, num: int) -> int:
        num_bit_length = 0
        process_num = num

        while process_num:
            num_bit_length += 1
            process_num >>= 1

        return num ^ ((1 << num_bit_length) - 1)


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [5],
        [1],
    ]

    for testcase in testcases_list:
        print(sol.findComplement(*testcase))
