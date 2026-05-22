from typing import List


class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        arr_length = len(arr)

        if (start < 0) or (start >= arr_length):
            return False

        indices_stack = list()
        indices_visited_list = [False] * arr_length

        # Mark start index as visited.
        indices_visited_list[start] = True

        # Push the start index into stack.
        indices_stack.append(start)

        # Use iterative DFS to check if we can jump to an index whose value
        # is 0 from the start index.
        while indices_stack:
            popped_index = indices_stack.pop()

            if 0 == (arr[popped_index]):
                return True

            destination_index_after_left_jump = (
                popped_index - (arr[popped_index])
            )

            if (
                (destination_index_after_left_jump >= 0)
                and
                (not (indices_visited_list[destination_index_after_left_jump]))
            ):
                indices_visited_list[destination_index_after_left_jump] = True
                indices_stack.append(destination_index_after_left_jump)

            destination_index_after_right_jump = (
                popped_index + (arr[popped_index])
            )

            if (
                (destination_index_after_right_jump < arr_length)
                and
                (not (indices_visited_list[destination_index_after_right_jump]))
            ):
                indices_visited_list[destination_index_after_right_jump] = True
                indices_stack.append(destination_index_after_right_jump)

        return False


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[4, 2, 3, 0, 3, 1, 2], 5],
        [[4, 2, 3, 0, 3, 1, 2], 0],
        [[3, 0, 2, 1, 2], 2],
    ]

    for testcase in testcases_list:
        print(sol.canReach(*testcase))
