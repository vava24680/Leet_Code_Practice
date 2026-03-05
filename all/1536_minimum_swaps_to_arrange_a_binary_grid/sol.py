from typing import List


def countTrailingConsecutiveZeros(row: List[int]) -> int:
    trailing_consecutive_zeros_count = 0

    for i in reversed(row):
        if i:
            break

        trailing_consecutive_zeros_count += 1

    return trailing_consecutive_zeros_count


class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        GRID_ROWS_NUMBER = len(grid)
        minimum_swap_operations_count = 0

        # Count consecutive trailing 0 in each row. */
        trailing_consecutive_zeros_list = [
            countTrailingConsecutiveZeros(row) for row in grid
        ]

        for row_index in range(GRID_ROWS_NUMBER):
            # Find the first target row that has enough consecutive trailing
            # zeros.
            for target_row_index in range(row_index, GRID_ROWS_NUMBER):
                if (
                    trailing_consecutive_zeros_list[target_row_index]
                    >=
                    (GRID_ROWS_NUMBER - 1 - row_index)
                ):
                    break
            else:
                minimum_swap_operations_count = -1

                break

            # Accumulate swaps count.
            minimum_swap_operations_count += (target_row_index - row_index)

            # Move the target row to row i by swaping two adjacent rows at a
            # time.
            for i in range(target_row_index, row_index, -1):
                (
                    trailing_consecutive_zeros_list[i],
                    trailing_consecutive_zeros_list[i - 1]
                )= (
                    trailing_consecutive_zeros_list[i - 1],
                    trailing_consecutive_zeros_list[i]
                )

        return minimum_swap_operations_count


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[[0, 0, 1], [1, 1, 0], [1, 0, 0]]],
        [[[0, 1, 1, 0], [0, 1, 1, 0], [0, 1, 1, 0], [0, 1, 1, 0]]],
        [[[1, 0, 0], [1, 1, 0], [1, 1, 1]]],
        [[[0, 0, 0], [1, 1, 0], [1, 0, 0]]],
    ]

    for testcase in testcases_list:
        print(sol.minSwaps(*testcase))
