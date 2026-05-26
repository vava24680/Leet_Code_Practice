from collections import deque
from typing import List


class Solution:
    def minJumps(self, arr: List[int]) -> int:
        arr_length = len(arr)
        minimum_jumps_count = 0
        value_and_unvisited_indices_set_map = dict()
        indices_visited_list = [False] * arr_length
        indices_queue = deque()

        # Set up value and unvisited indices map.
        for index, value in enumerate(arr):
            if value not in value_and_unvisited_indices_set_map:
                value_and_unvisited_indices_set_map[value] = set()

            (value_and_unvisited_indices_set_map[value]).add(index)

        # Mark the start index as visited.
        (value_and_unvisited_indices_set_map[arr[0]]).discard(0)

        # Enque the start index.
        indices_queue.append(0)

        while indices_queue:
            queue_length = len(indices_queue)

            for _ in range(queue_length):
                popped_index = indices_queue.popleft()

                if (arr_length - 1) == popped_index:
                    return minimum_jumps_count

                if (
                    ((popped_index - 1) >= 0)
                    and
                    (
                        (popped_index - 1)
                        in
                        (
                            value_and_unvisited_indices_set_map[
                                arr[popped_index - 1]
                            ]
                        )
                    )
                ):
                    # Enque the left index if it is not visited.
                    (
                        value_and_unvisited_indices_set_map[
                            arr[popped_index - 1]
                        ]
                    ).discard(
                        popped_index - 1
                    )
                    indices_queue.append(popped_index - 1)

                if (
                    ((popped_index + 1) < arr_length)
                    and
                    (
                        (popped_index + 1)
                        in
                        (
                            value_and_unvisited_indices_set_map[
                                arr[popped_index + 1]
                            ]
                        )
                    )
                ):
                    # Enque the right index if it is not visited.
                    (
                        value_and_unvisited_indices_set_map[
                            arr[popped_index + 1]
                        ]
                    ).discard(
                        popped_index + 1
                    )
                    indices_queue.append(popped_index + 1)

                while (value_and_unvisited_indices_set_map[arr[popped_index]]):
                    # Euque all the indices that are not visited and have the
                    # same value as current popped index.
                    indices_queue.append(
                        (value_and_unvisited_indices_set_map[arr[popped_index]]).pop()
                    )

            minimum_jumps_count += 1

        return -1


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[100, -23, -23, 404, 100, 23, 23, 23, 3, 404]],
        [[7]],
        [[7, 6, 9, 6, 9, 6, 9, 7]],
        [[101, 102, 103, 105, 107, 108, 109, 20000]],
        [[11, 22, 7, 7, 7, 7, 7, 7, 7, 22, 13]],
        [
            [
                68, -94, -44, -18, -1, 18, -87, 29, -6, -87, -27, 37, -57, 7,
                18, 68, -59, 29, 7, 53, -27, -59, 18, -1, 18, -18, -59, -1, -18,
                -84,-20,7,7,-87,-18,-84,-20,-27,
            ]
        ],
    ]

    for testcase in testcases_list:
        print(sol.minJumps(*testcase))
