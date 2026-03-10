from typing import List


class Solution:
    def fairCandySwap(
        self,
        aliceSizes: List[int],
        bobSizes: List[int]
    ) -> List[int]:
        aliceSizes_length = len(aliceSizes)
        bobSizes_length = len(bobSizes)
        delta = ((sum(aliceSizes) - sum(bobSizes)) >> 1)
        result_list = list()

        # Sort the given two lists in ascending order.
        aliceSizes.sort()
        bobSizes.sort()

        i = j = 0

        while (i < aliceSizes_length) and (j < bobSizes_length):
            current_candy_count_difference = (aliceSizes[i] - bobSizes[j])

            if delta == current_candy_count_difference:
                result_list.append(aliceSizes[i])
                result_list.append(bobSizes[j])

                break
            elif current_candy_count_difference < delta:
                # Increase i to increase the candy count difference.
                i += 1
            else:
                # Increase j to decrease the candy count difference.
                j += 1

        return result_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 1], [2, 2]],
        [[1, 2], [2, 3]],
        [[2], [1, 3]],
    ]

    for testcase in testcases_list:
        print(sol.fairCandySwap(*testcase))
