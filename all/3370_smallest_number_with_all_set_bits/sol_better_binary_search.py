class Solution:
    def smallestNumber(self, n: int) -> int:
        left_bits_length = 1
        right_bits_length = 32

        while left_bits_length < right_bits_length:
            middle_bits_length = (
                left_bits_length
                +
                ((right_bits_length - left_bits_length) >> 1)
            )

            if (1 << middle_bits_length) <= n:
                left_bits_length = middle_bits_length + 1
            else:
                right_bits_length = middle_bits_length

        return (1 << left_bits_length) - 1
