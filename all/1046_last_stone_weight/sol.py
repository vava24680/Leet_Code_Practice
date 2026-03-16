import heapq

from typing import List


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # As Python's built-in heapq libraray is min-heap, we convert all
        # numbers in the given array to negative values and use min-heap
        # to mimic max-heap.
        stones = [-stone for stone in stones]
        heapq.heapify(stones)

        while len(stones) >= 2:
            first_heavy_stone = abs(heapq.heappop(stones))
            second_heavy_stone = abs(heapq.heappop(stones))

            if first_heavy_stone > second_heavy_stone:
                heapq.heappush(
                    stones,
                    -(first_heavy_stone - second_heavy_stone)
                )

        return abs(stones[0]) if stones else 0


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[2, 7, 4, 1, 8, 1]],
        [[1]],
    ]

    for testcase in testcases_list:
        print(sol.lastStoneWeight(*testcase))
