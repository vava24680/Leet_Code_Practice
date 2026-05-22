from collections import deque
from typing import List


class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        arr_length = len(arr)

        if (start < 0) or (start >= arr_length):
            return False

        indices_queue = deque()

        # Mark start index as visited by changing its element value to negative
        # value.
        arr[start] = (-(arr[start]))

        # Enque start index.
        indices_queue.append(start)

        # Use BFS to check if we can jump to an index whose value is 0 from the
        # start index.
        while indices_queue:
            popped_index = indices_queue.popleft()

            if 0 == (arr[popped_index]):
                return True

            destination_index_after_left_jump = (
                popped_index - abs(arr[popped_index])
            )

            if (
                (destination_index_after_left_jump >= 0)
                and
                ((arr[destination_index_after_left_jump]) >= 0)
            ):
                # Mark an index as visited by changing its element value to
                # negative value.
                arr[destination_index_after_left_jump] = (
                    -(arr[destination_index_after_left_jump])
                )
                indices_queue.append(destination_index_after_left_jump)

            destination_index_after_right_jump = (
                popped_index + abs(arr[popped_index])
            )

            if (
                (destination_index_after_right_jump < arr_length)
                and
                ((arr[destination_index_after_right_jump]) >= 0)
            ):
                # Mark an index as visited by changing its element value to
                # negative value.
                arr[destination_index_after_right_jump] = (
                    -(arr[destination_index_after_right_jump])
                )
                indices_queue.append(destination_index_after_right_jump)

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
