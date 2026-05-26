from collections import deque
from typing import List


class Solution:
    def minJumps(self, arr: List[int]) -> int:
        arr_length = len(arr)
        value_and_indices_set_dict = dict()
        bfs_info_dict = {
            'left': {
                'current_jumps_count': 0,
                'indices_minimum_jumps_list': [-1] * arr_length,
                'indices_queue': deque(),
            },
            'right': {
                'current_jumps_count': 0,
                'indices_minimum_jumps_list': [-1] * arr_length,
                'indices_queue': deque(),
            },
        }

        # Set up value and unvisited indices map.
        for index, value in enumerate(arr):
            if value not in value_and_indices_set_dict:
                value_and_indices_set_dict[value] = set()

            (value_and_indices_set_dict[value]).add(index)

        # It takes 0 jumps from index 0 to index 0.
        bfs_info_dict['left']['indices_minimum_jumps_list'][0] = 0

        # Enque the start index to the first queue.
        (bfs_info_dict['left']['indices_queue']).append(0)

        # It takes 0 jumps from last index to last index.
        bfs_info_dict['right']['indices_minimum_jumps_list'][arr_length - 1] = 0

        # Enque the last index to the second queue.
        (bfs_info_dict['right']['indices_queue']).append(arr_length - 1)

        while (
            (bfs_info_dict['left']['indices_queue'])
            and
            (bfs_info_dict['right']['indices_queue'])
        ):
            indices_queue_1_length = len(bfs_info_dict['left']['indices_queue'])
            indices_queue_2_length = len(
                bfs_info_dict['right']['indices_queue']
            )

            if indices_queue_1_length < indices_queue_2_length:
                operated_bfs_info = (bfs_info_dict['left'])
                the_other_operated_bfs_info = (bfs_info_dict['right'])
            else:
                operated_bfs_info = (bfs_info_dict['right'])
                the_other_operated_bfs_info = (bfs_info_dict['left'])

            operated_indices_queue_length = len(
                operated_bfs_info['indices_queue']
            )

            for _ in range(operated_indices_queue_length):
                popped_index = (operated_bfs_info['indices_queue']).popleft()

                if (
                    (
                        the_other_operated_bfs_info[
                            'indices_minimum_jumps_list'
                        ][
                            popped_index
                        ]
                    )
                    >=
                    0
                ):
                    # If current popped index is visitied in the other BFS
                    # traversal, it means two BFS traversals intersect,
                    # we find minimum jumps count from index 0 to the last index.
                    # The value will be jumps count recorded in current BFS
                    # traversal plus the minimum jumps count to jump to this
                    # popped index in the other BFS traversal.
                    return (
                        (operated_bfs_info['current_jumps_count'])
                        +
                        (
                            the_other_operated_bfs_info[
                                'indices_minimum_jumps_list'
                            ][
                                popped_index
                            ]
                        )
                    )

                # Gather all valid destination indices.
                valid_destination_indices_list = list(
                    value_and_indices_set_dict[arr[popped_index]]
                )
                (value_and_indices_set_dict[arr[popped_index]]).clear()

                if ((popped_index - 1) >= 0):
                    valid_destination_indices_list.append(popped_index - 1)

                if ((popped_index + 1) < arr_length):
                    valid_destination_indices_list.append(popped_index + 1)

                # Enque all destination indices which are good to jump to.
                for destination_index in valid_destination_indices_list:
                    if (
                        (
                            operated_bfs_info[
                                'indices_minimum_jumps_list'
                            ][
                                destination_index
                            ]
                        )
                        >=
                        0
                    ):
                        # Skip a visited index.
                        continue

                    # Record the minimum jumps count from source to a
                    # destination index.
                    (
                        operated_bfs_info[
                            'indices_minimum_jumps_list'
                        ][
                            destination_index
                        ]
                    )= (
                        (operated_bfs_info['current_jumps_count']) + 1
                    )
                    (operated_bfs_info['indices_queue']).append(
                        destination_index
                    )

            (operated_bfs_info['current_jumps_count']) += 1

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
