class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        binary_values_list = [0] * ((1 << n) - 1)

        for i in range(1, n):
            current_string_length = ((1 << i) - 1)

            if (k - 1) < current_string_length:
                # Break if current string is long enough to get answer.
                break

            binary_values_list[current_string_length] = 1

            for j in range(current_string_length):
                binary_values_list[current_string_length + 1 + j] = (
                    1 - binary_values_list[current_string_length - 1 - j]
                )

        return chr(ord('0') + binary_values_list[k - 1])


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [3, 1],
        [4, 11],
        [10, 896],
    ]

    for testcase in testcases_list:
        print(sol.findKthBit(*testcase))
