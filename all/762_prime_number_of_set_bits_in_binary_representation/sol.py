PRIME_NUMBERS_SET = {2, 3, 5, 7, 11, 13, 17, 19}


class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        count = 0

        def countSetBits(n: int) -> int:
            set_bits_count = 0

            while n:
                set_bits_count += 1
                n &= (n - 1)

            return set_bits_count

        for number in range(left, right + 1):
            if countSetBits(number) in PRIME_NUMBERS_SET:
                count += 1

        return count
