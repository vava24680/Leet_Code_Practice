from typing import List


def countSetBit(x: int) -> int:
    x = ((x & 0x5555555555555555) + ((x >> 1) & 0x5555555555555555))
    x = ((x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333))
    x = ((x & 0x0F0F0F0F0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F0F0F0F0F))
    x = ((x & 0x00FF00FF00FF00FF) + ((x >> 8) & 0x00FF00FF00FF00FF))
    x = ((x & 0x0000FFFF0000FFFF) + ((x >> 16) & 0x0000FFFF0000FFFF))
    x = ((x & 0x00000000FFFFFFFF) + ((x >> 32) & 0x00000000FFFFFFFF))

    return x


class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        answer_list = list()
        bitmap_1, bitmap_2 = 0, 0

        for num_1, num_2 in zip(A, B):
            # Set corresponding bit to 1 int bitmap 1.
            bitmap_1 |= (1 << num_1)

            # Set corresponding bit to 1 int bitmap 2.
            bitmap_2 |= (1 << num_2)

            # The count of set bits in the (bitmap_1 & bitmap_2) is the count
            # of numbers that shows in both of list A and list B.
            answer_list.append(countSetBit(bitmap_1 & bitmap_2))

        return answer_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 3, 2, 4], [3, 1, 2, 4]],
        [[2, 3, 1], [3, 1, 2]],
    ]

    for testcase in testcases_list:
        print(sol.findThePrefixCommonArray(*testcase))
