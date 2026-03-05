class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        if 1 == n:
            return '0'

        current_string_length = ((1 << n) - 1);

        if (k - 1) == (current_string_length >> 1):
            return '1'
        elif (k - 1) < (current_string_length >> 1):
            return self.findKthBit(n - 1, k)

        return chr(
            ord('1')
            -
            ord(self.findKthBit(n - 1, current_string_length - k + 1))
            +
            ord('0')
        )


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [3, 1],
        [4, 11],
        [10, 896],
    ]

    for testcase in testcases_list:
        print(sol.findKthBit(*testcase))
