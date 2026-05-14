from typing import List


class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        if not grid:
            return False

        GRID_ROWS_NUMBER = len(grid)
        GRID_COLUMNS_NUMBER = len(grid[0])
        MOVEMENTS_LIST = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        visited_matrix = [
            [False] * GRID_COLUMNS_NUMBER for _ in range(GRID_ROWS_NUMBER)
        ]

        def detectCycleViaDFS(
            start_cell_value: int,
            previous_row_index: int,
            previous_column_index: int,
            current_row_index: int,
            current_column_index: int
        ) -> bool:
            # Mark current cell as visited.
            nonlocal visited_matrix

            visited_matrix[current_row_index][current_column_index] = True

            for d_row, d_column in MOVEMENTS_LIST:
                new_row_index = (current_row_index + d_row)
                new_column_index = (current_column_index + d_column)

                if (
                    (new_row_index < 0)
                    or
                    (new_row_index >= GRID_ROWS_NUMBER)
                    or
                    (new_column_index < 0)
                    or
                    (new_column_index >= GRID_COLUMNS_NUMBER)
                ):
                    # Continue to next new row index and new column index
                    # if current one is invalid.
                    continue

                if start_cell_value != (grid[new_row_index][new_column_index]):
                    # Continue to next new row index and new column index if
                    # the new cell's value is not matched with the start cell
                    # value.
                    continue

                if visited_matrix[new_row_index][new_column_index]:
                    if (
                        (previous_row_index != new_row_index)
                        or
                        (previous_column_index != new_column_index)
                    ):
                        # If the following conditions are met, it means there
                        # is a valid cycle in the given grid.
                        # 1. New row index and new column index does not equal
                        #    to the previous row index and previous column index.
                        # 2. New cell is already visited.
                        return True

                    # Continue to next new row index and new column index if
                    # new cell is the previously visited cell.
                    continue

                if detectCycleViaDFS(
                    start_cell_value,
                    current_row_index,
                    current_column_index,
                    new_row_index,
                    new_column_index
                ):
                    # Return true if following DFS detects a cycle in the
                    # given grid.
                    return True

            # Do not set current cell as unvisited here since we do not need to
            # take other cell in the current path as start cell since there does
            # not exist a cycle.
            return False

        for row_index in range(GRID_ROWS_NUMBER):
            for column_index in range(GRID_COLUMNS_NUMBER):
                # Try every unvisited cell in the given grid as start point and
                # check if there is a valid cycle.
                if (
                    (not visited_matrix[row_index][column_index])
                    and
                    detectCycleViaDFS(
                        grid[row_index][column_index],
                        row_index,
                        column_index,
                        row_index,
                        column_index
                    )
                ):
                    return True

        return False


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [
            [
                ["a", "a" ,"a", "a"],
                ["a", "b", "b", "a"],
                ["a", "b", "b", "a"],
                ["a", "a", "a", "a"],
            ]
        ],
        [
            [
                ['c', 'c', 'c', 'a'],
                ['c', 'd', 'c', 'c'],
                ['c', 'c', 'e', 'c'],
                ['f', 'c', 'c', 'c'],
            ]
        ],
        [
            [
                ['a', 'b', 'b'],
                ['b', 'z', 'b'],
                ['b', 'b', 'a'],
            ]
        ],
    ]

    for testcase in testcases_list:
        print(sol.containsCycle(*testcase))
