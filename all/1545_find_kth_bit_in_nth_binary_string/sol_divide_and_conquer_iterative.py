class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        invert_count = 0

        for i in reversed(range(2, n + 1)):
            current_string_length = ((1 << i) - 1)

            if (k - 1) == (current_string_length >> 1):
                # Need to consider invert count before return.
                return '0' if invert_count & 0x1 else '1'
            elif (k - 1) > (current_string_length >> 1):
                # Increase invert count by 1.
                invert_count += 1
                k = (current_string_length - k + 1)

        if invert_count & 0x1:
            return '1'

        return '0'


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [3, 1],
        [4, 11],
        [10, 896],
    ]

    for testcase in testcases_list:
        print(sol.findKthBit(*testcase))
