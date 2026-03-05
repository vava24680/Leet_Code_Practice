class Solution:
    def smallestNumber(self, n: int) -> int:
        bits_length = n.bit_length()

        return (1 << bits_length) - 1
