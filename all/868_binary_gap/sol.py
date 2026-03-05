class Solution:
    def binaryGap(self, n: int) -> int:
        maximum_distance_between_adjacent_ones = 0
        previous_one_bit_position = None
        bit_position = 0

        while n:
            if 1 == (n & 0x1):
                if previous_one_bit_position is not None:
                    maximum_distance_between_adjacent_ones = max(
                        maximum_distance_between_adjacent_ones,
                        bit_position - previous_one_bit_position
                    )

                previous_one_bit_position = bit_position

            n >>= 1
            bit_position += 1

        return maximum_distance_between_adjacent_ones


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [22],
        [8],
        [5],
    ]

    for testcase in testcases_list:
        print(sol.binaryGap(*testcase))
