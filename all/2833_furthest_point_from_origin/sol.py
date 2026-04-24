class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        left_moves_count = 0
        right_moves_count = 0
        undecided_direction_moves_count = 0

        for move in moves:
            if 'L' == move:
                left_moves_count += 1
            elif 'R' == move:
                right_moves_count += 1
            else:
                undecided_direction_moves_count += 1

        return (
            abs(left_moves_count - right_moves_count)
            +
            undecided_direction_moves_count
        )


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['L_RL__R'],
        ['_R__LL_'],
        ['_______'],
    ]

    for testcase in testcases_list:
        print(sol.furthestDistanceFromOrigin(*testcase))
