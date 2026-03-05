class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        substrings_showed_list = [False] * (1 << k)
        current_binary_string_value = 0
        binary_string_value_bitmask = ((1 << k) - 1)

        for window_right_index, c in enumerate(s):
            current_binary_string_value = (
                (current_binary_string_value << 1) | (int(c))
            )

            if window_right_index >= (k - 1):
                current_binary_string_value &= binary_string_value_bitmask
                substrings_showed_list[current_binary_string_value] = True

        return all(substrings_showed_list)
