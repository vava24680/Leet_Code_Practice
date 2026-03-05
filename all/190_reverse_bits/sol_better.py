class Solution:
    def reverseBits(self, n: int) -> int:
        result = n

        for lower_bit_index in range(16):
            higher_bit_index = 31 - lower_bit_index
            lower_bit_value = (
                (result & (1 << lower_bit_index)) >> lower_bit_index
            )
            higher_bit_value = (
                (result & (1 << higher_bit_index)) >> higher_bit_index
            )

            if lower_bit_value == higher_bit_value:
                # No need to swap two bits' values if there are the same.
                continue

            # Swap two bits' values if there are different.
            # As bit value 1 will be changed to bit value 0 and vice versa,
            # we can use XOR operation to do that.
            result ^= ((1 << lower_bit_index) | (1 << higher_bit_index))

        return result & 0xFFFFFFFF


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [43261596],
        [2147483644],
    ]

    for testcase in testcases_list:
        print(sol.reverseBits(*testcase))
