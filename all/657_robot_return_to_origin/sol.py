class Solution:
    def judgeCircle(self, moves: str) -> bool:
        # Use two variables to record horizontal and vertical movement amout.
        # If a 'U' movement instruction is used, increase vertical movement by 1.
        # If a 'D' movement instruction is used, decrease vertical movement by 1.
        # If a 'R' movement instruction is used, increase horizontal movement by 1.
        # If a 'L' movement instruction is used, decrease horizontal movement by 1.
        #
        # After all movement instructions, if vertical movement amount
        # and horizontal movement amount are all zero, it means the robot goes
        # back to the start position. Otherwises, it's not stay at the start
        # position.
        horizontal_movement_amount = 0
        vertical_movement_amount = 0

        for move in moves:
            if 'U' == move:
                vertical_movement_amount += 1
            elif 'D' == move:
                vertical_movement_amount -= 1
            elif 'R' == move:
                horizontal_movement_amount += 1
            elif 'L' == move:
                horizontal_movement_amount -= 1
            else:
                return False

        return (
            (0 == vertical_movement_amount)
            and
            (0 == horizontal_movement_amount)
        )


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['UD'],
        ['LL'],
    ]

    for testcase in testcases_list:
        print(sol.judgeCircle(*testcase))
