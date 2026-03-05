class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        # If a positive number n whose binary representation has alternating bits,
        # n ^ (n >> 1) results in a number whose binary representation is composed
        # by a bunch of consecutinve 1 from LSB.
        #
        # To test is a number n binary representation is composed by a bunch of
        # consecutinve 1 from LSB, we can check if n & (n + 1) is zero, if it is,
        # then binary representation of n is composed by a bunch of consecutinve
        # 1 from LSB.
        tmp = n ^ (n >> 1)

        return 0 == (tmp & (tmp + 1))
