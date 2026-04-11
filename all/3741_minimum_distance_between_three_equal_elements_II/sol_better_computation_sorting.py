from typing import List


class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        minimum_distance = float('inf')
        value_index_tuples_list = [
            (num, index) for index, num in enumerate(nums)
        ]

        # Sort all pairs by value and index in the ascending order.
        value_index_tuples_list.sort()

        first_index = 0

        while first_index < (len(nums) - 3 + 1):
            if (
                (value_index_tuples_list[first_index][0])
                !=
                (value_index_tuples_list[first_index + 1][0])
            ):
                # Value in the current pair is not equal to the value in the
                # next pair, continue to next pair to try to find a good tuple.
                first_index += 1

                continue
            elif (
                (value_index_tuples_list[first_index][0])
                !=
                (value_index_tuples_list[first_index + 2][0])
            ):
                # Value in the current pair is not equal to the value in the
                # pair after the next pair, continue to the pair after the next
                # pair to try to find a good tuple.
                first_index += 2

                continue

            # Find a good tuple, compute its distance and update global minimum
            # distance if needed.
            minimum_distance = min(
                minimum_distance,
                (
                    (value_index_tuples_list[first_index + 2][1])
                    -
                    (value_index_tuples_list[first_index][1])
                )
                <<
                1
            )

            # Move to next pair to try to find a good tuple that might have
            # minimum distance.
            first_index += 1

        if float('inf') == minimum_distance:
            return -1

        return minimum_distance


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 2, 1, 1, 3]],
        [[1, 1, 2, 3, 2, 1, 2]],
        [[1]],
    ]

    for testcase in testcases_list:
        print(sol.minimumDistance(*testcase))
