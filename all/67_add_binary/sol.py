class Solution:
    def addBinary(self, a: str, b: str) -> str:
        carry_bit_value = 0

        if len(a) <= len(b):
            longer_binary_string, shorter_binary_string = b, a
        else:
            longer_binary_string, shorter_binary_string = a, b

        longer_binary_string = longer_binary_string[::-1]
        shorter_binary_string = shorter_binary_string[::-1]
        longer_binary_string_length = len(longer_binary_string)
        shorter_binary_string_length = len(shorter_binary_string)

        answer = ['0'] * longer_binary_string_length

        for index in range(shorter_binary_string_length):
            sum_val = (
                carry_bit_value
                +
                int(longer_binary_string[index])
                +
                int(shorter_binary_string[index])
            )
            answer[index] = str(sum_val & 1)
            carry_bit_value = sum_val >> 1

        for index in range(
            shorter_binary_string_length,
            longer_binary_string_length
        ):
            sum_val = carry_bit_value + int(longer_binary_string[index])
            answer[index] = str(sum_val & 1)
            carry_bit_value = sum_val >> 1

        if carry_bit_value:
            answer.append('1')

        return ''.join(reversed(answer))


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['11', '1'],
        ['1010', '1011'],
        ['10101', '1'],
    ]

    for testcase in testcases_list:
        print(sol.addBinary(*testcase))
