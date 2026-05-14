from collections import deque
from typing import List


def unionFindFind(parents_list: List[int], i: int) -> int:
    if i >= len(parents_list):
        return -1

    root = i

    # Find root of a given node.
    while root != (parents_list[root]):
        root = (parents_list[root])

    current_i = i

    # Do path compresion to make all the nodes that have same ancestor point to
    # the ancestor directly.
    while root != (parents_list[current_i]):
        original_parent = (parents_list[current_i])
        (parents_list[current_i]) = root
        current_i = original_parent

    return root


def unionFindUnion(parents_list: List[int], i: int, j: int) -> bool:
    if (i >= len(parents_list)) or (j >= len(parents_list)):
        return False

    root_of_i = unionFindFind(parents_list, i)
    root_of_j = unionFindFind(parents_list, j)

    (parents_list[root_of_j]) = root_of_i

    return True


class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        if not grid:
            return False

        GRID_ROWS_NUMBER = len(grid)
        GRID_COLUMNS_NUMBER = len(grid[0])
        MOVEMENTS_LIST = [(1, 0), (0, 1)]

        parents_list = [
            i for i in range(GRID_ROWS_NUMBER * GRID_COLUMNS_NUMBER)
        ]

        # Try every cell in the grid and use unio find to detect if a cycle
        # exists in the given grid.
        #
        # Check notes for details.
        for row_index in range(GRID_ROWS_NUMBER):
            for column_index in range(GRID_COLUMNS_NUMBER):
                current_cell_flatted_index = (
                    (row_index * GRID_COLUMNS_NUMBER) + column_index
                )

                for d_row, d_column in MOVEMENTS_LIST:
                    new_row_index = (row_index + d_row)
                    new_column_index = (column_index + d_column)

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

                    new_cell_flatted_index = (
                        (new_row_index * GRID_COLUMNS_NUMBER) + new_column_index
                    )

                    if (
                        (grid[row_index][column_index])
                        !=
                        (grid[new_row_index][new_column_index])
                    ):
                        # Continue to next new row index and new column index if
                        # the new cell's value is not matched with the start cell
                        # value.
                        continue

                    if (
                        unionFindFind(parents_list, current_cell_flatted_index)
                        ==
                        unionFindFind(parents_list, new_cell_flatted_index)
                    ):
                        # If two cells have same ancestor, they are in the same
                        # connected component, which means by connecting these
                        # two cells together can result in a cycle.
                        return True
                    else:
                        # Union the current cell and the new cell if they do not
                        # have same ancestor yet.
                        unionFindUnion(
                            parents_list,
                            current_cell_flatted_index,
                            new_cell_flatted_index
                        )

        return False


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [
            [
                ['a', 'a' ,'a', 'a'],
                ['a', 'b', 'b', 'a'],
                ['a', 'b', 'b', 'a'],
                ['a', 'a', 'a', 'a'],
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
        [
            [
                ['b', 'c', 'a', 'a'],
                ['d', 'a', 'a', 'a'],
                ['a', 'b', 'a', 'c'],
            ]
        ],
    ]

    for testcase in testcases_list:
        print(sol.containsCycle(*testcase))
