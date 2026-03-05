class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        current_bits_list = ['1'] * k

        for i in range(1 << k):
            carry_value = 1

            for bit_index in reversed(range(k)):
                old_current_bit_value = int(current_bits_list[bit_index])
                current_bits_list[bit_index] = str(
                    (int(current_bits_list[bit_index])) ^ carry_value
                )

                if not (carry_value and old_current_bit_value):
                    break

                carry_value = 1

            if ''.join(current_bits_list) not in s:
                return False

        return True
