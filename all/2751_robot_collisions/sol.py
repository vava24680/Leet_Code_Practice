from dataclasses import dataclass
from typing import List


@dataclass
class RobotInfo:
    position: int
    health: int
    direction: str
    original_index: int


class Solution:
    def survivedRobotsHealths(
        self,
        positions: List[int],
        healths: List[int],
        directions: str
    ) -> List[int]:
        robots_info_list = [
            RobotInfo(position, health, direction, index)
            for index, (position, health, direction) in enumerate(
                zip(positions, healths, directions)
            )
        ]

        # Sort all the robots information according to position in ascending
        # order.
        robots_info_list.sort(key=lambda o: o.position)

        # Use the original list as stack to save space.
        robots_info_stack = robots_info_list
        stack_next_available_index = 0

        for robot_info in robots_info_list:
            while (
                stack_next_available_index
                and
                (
                    ('L' == robot_info.direction)
                    and
                    (
                        'R'
                        ==
                        (robots_info_stack[stack_next_available_index - 1]).direction
                    )
                )
            ):
                # Collide with robot at the stack top.

                # Get the robot information at the stack top.
                stack_top_robot_info = (
                    robots_info_stack[stack_next_available_index - 1]
                )

                if (robot_info.health) > (stack_top_robot_info.health):
                    # Current robot has more health points than the robot
                    # at the stack top.

                    # Decrease the current robot health points by 1.
                    (robot_info.health) -= 1

                    # Pop out the robot at the stack pop by decreasing
                    # the stack next available index by 1.
                    stack_next_available_index -= 1
                else:
                    # Current robot does not have more health points than
                    # the robot at the stack top.
                    if (robot_info.health) < (stack_top_robot_info.health):
                        # Current robot has less health points than the
                        # robot at the stack top.
                        # Decrease the health points of the robot at the
                        # stack top by 1.
                        stack_top_robot_info.health -= 1
                    else:
                        # Current robot has same health points as the robot
                        # at the stack top.

                        # Pop out the robot at the stack pop by decreasing
                        # the stack next available index by 1.
                        stack_next_available_index -= 1

                    # In either ease, do not need to check further
                    # collision, so we can break the while loop.
                    break
            else:
                # Push current robot information to the stack.

                # There thre cases that program will be here:
                # 1. Stack is empty.
                # 2. Current robot does not collide with previous robot.
                # 3. Current robot collides with many robots and it always win
                #    until it does not collide with a robot anymore.

                robots_info_stack[stack_next_available_index] = robot_info
                stack_next_available_index += 1

        # Remove all the robots that are not alive.
        del robots_info_list[stack_next_available_index:]

        # Sort all the remaining robots with their original indices in the
        # ascending order.
        robots_info_list.sort(key=lambda o: o.original_index)

        return [robot_info.health for robot_info in robots_info_stack]


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[5, 4, 3, 2, 1], [2, 17, 9, 15, 10], 'RRRRR'],
        [[3, 5, 2, 6], [10, 10, 15, 12], 'RLRL'],
        [[1, 2, 5, 6], [10, 10, 11, 11], 'RLRL'],
        [[1, 40], [10, 11], 'RL'],
        [[1, 40], [10, 11], 'LR'],
    ]

    for testcase in testcases_list:
        print(sol.survivedRobotsHealths(*testcase))
