from typing import List


class Solution:
    def fairCandySwap(
        self,
        aliceSizes: List[int],
        bobSizes: List[int]
    ) -> List[int]:
        result_list = []

        # Check which list is shorter.
        if len(aliceSizes) < len(bobSizes):
            shorter_list = aliceSizes
            longer_list = bobSizes
            are_two_lists_switched = False
        else:
            shorter_list = bobSizes
            longer_list = aliceSizes
            are_two_lists_switched = True

        delta = (sum(shorter_list) - sum(longer_list)) // 2
        shorter_list_set = set(shorter_list)

        for candy_count in longer_list:
            if (candy_count + delta) in shorter_list_set:
                result_list.append(candy_count + delta)
                result_list.append(candy_count)

                break

        if are_two_lists_switched:
            # Switch back the answer order if the original two lists are
            # switched.
            result_list[0], result_list[1] = result_list[1], result_list[0]

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
