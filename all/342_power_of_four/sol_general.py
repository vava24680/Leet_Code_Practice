class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        # This Python solution is suitable for any large number.
        # The last expression check a power of two number has the bit value 1
        # set on an odd bit.
        # If a number is power of four, the bit value 1 must be set on an even
        # bit and the bit length to represent itself should be a odd number.
        # For example:
        # 4: 0b100, bit 2 is set, and the bit length is 3
        # 16: 0b10000, bit 4 is set, and the bit length is 5.
        #
        # Ref: ChatGPT
        return (n > 0) and (0 == (n & (n - 1))) and (1 == (n.bit_length() & 1))
