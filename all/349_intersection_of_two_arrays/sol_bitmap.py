import math

from typing import List


MAX_ELEMENT_VALUE = 1000
BITMAP_BITS_COUNT = 64


class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        answer_list = list()
        bitmap_list = (
            [0] * (math.ceil((MAX_ELEMENT_VALUE + 1) / BITMAP_BITS_COUNT))
        )

        for num in nums1:
            # Iterate all values in the nums1 list to set up the bitmap list.
            bitmap_list[num // BITMAP_BITS_COUNT] |= (
                1 << (num % BITMAP_BITS_COUNT)
            )

        for num in nums2:
            if (
                bitmap_list[num // BITMAP_BITS_COUNT]
                &
                (1 << (num % BITMAP_BITS_COUNT))
            ):
                answer_list.append(num)

                # After finding a new intersected value, we clear the
                # corresponding bit in the bitmap list to avoid repeated
                # matching.
                bitmap_list[num // BITMAP_BITS_COUNT] &= (
                    ~(1 << (num % BITMAP_BITS_COUNT))
                )

        return answer_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 2, 2, 1], [2, 2]],
        [[4, 9, 5], [9, 4, 9, 8, 4]],
    ]

    for testcase in testcases_list:
        print(sol.intersection(*testcase))
