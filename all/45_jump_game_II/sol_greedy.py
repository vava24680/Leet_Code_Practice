from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:
        minimum_jumps_count = 0
        # This variable represents the farthest index that current jump can
        # reach.
        current_jump_maximum_index = 0

        # This variable represents the farthest index that can be reached from
        # the indices that we have traversed.
        #
        # This variable remains same functionality as in the LeetCode 55.
        farthest_index_can_be_reached = 0

        for i in range(len(nums) - 1):
            # Update the farthest index that can be reached from the indices
            # that we have traversed.
            #
            # This check is optional.
            farthest_index_can_be_reached = max(
                farthest_index_can_be_reached,
                i + nums[i]
            )

            if i == current_jump_maximum_index:
                # If we need to a new jump but the farthest index that can be
                # reached from the indices we have traversed is less than or
                # equal to the farthest index that current jump can contribute,
                # it means new jump cannot take us farther, so it's impossible
                # to reach the target index.
                if farthest_index_can_be_reached <= current_jump_maximum_index:
                    return -1

                # If current index is equal to the farthest index that current
                # jump can contribute, we must make another jump as next index
                # is not reachable by current jump.
                #
                # So we increase jump count by 1, we also update the farthest
                # index that this new jump can contribute as the farthest index
                # that can be reached from the indices we have traversed.
                minimum_jumps_count += 1
                current_jump_maximum_index = farthest_index_can_be_reached

        # Make sure the last index is covered within the range of the farthest
        # index can be reached from the indices that we have traversed.
        #
        # This check is optional.
        if farthest_index_can_be_reached < ((len(nums)) - 1):
            return -1

        return minimum_jumps_count


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[2, 3, 1, 1, 4]],
        [[2, 3, 0, 1, 4]],
        [[2, 1, 0, 0, 4]],
        [[1, 1, 0]],
        [[1, 2, 0, 0, 0]],
    ]

    for testcase in testcases_list:
        print(sol.jump(*testcase))
