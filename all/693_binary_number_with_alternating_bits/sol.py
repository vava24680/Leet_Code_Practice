class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        previous_bit = n & 1
        process_number = n >> 1

        while process_number:
            if previous_bit == (process_number & 1):
                return False

            previous_bit = process_number & 1
            process_number >>= 1

        return True
