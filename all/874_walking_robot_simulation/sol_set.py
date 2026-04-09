from enum import Enum
from typing import List


class DirectionEnum(Enum):
    UP = 0
    DOWN = 1
    LEFT = 2
    RIGHT = 3


DX_DICT = {
    DirectionEnum.UP: 0,
    DirectionEnum.DOWN: 0,
    DirectionEnum.LEFT: -1,
    DirectionEnum.RIGHT: 1,
}
DY_DICT = {
    DirectionEnum.UP: 1,
    DirectionEnum.DOWN: -1,
    DirectionEnum.LEFT: 0,
    DirectionEnum.RIGHT: 0,
}


def determineNewDirection(
    current_direction: DirectionEnum,
    turning_value: int
) -> DirectionEnum:
    if (-1 != turning_value) and (-2 != turning_value):
        raise ValueError(f'Unknown turning value: {turning_value}')

    if DirectionEnum.UP == current_direction:
        return (
            DirectionEnum.RIGHT if -1 == turning_value else DirectionEnum.LEFT
        )
    elif DirectionEnum.DOWN == current_direction:
        return (
            DirectionEnum.LEFT if -1 == turning_value else DirectionEnum.RIGHT
        )
    elif DirectionEnum.LEFT == current_direction:
        return (
            DirectionEnum.UP if -1 == turning_value else DirectionEnum.DOWN
        )
    elif DirectionEnum.RIGHT == current_direction:
        return (
            DirectionEnum.DOWN if -1 == turning_value else DirectionEnum.UP
        )

    raise ValueError(f'Unknown direction: {current_direction}')


class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        maximum_euclidean_distance = 0
        current_direction = DirectionEnum.UP
        obstacles_set = {(x, y) for x, y in obstacles}
        current_x_coordinate = 0
        current_y_coordinate = 0

        for command in commands:
            if command < 0:
                # Turn command.
                current_direction = determineNewDirection(
                    current_direction,
                    command
                )
            else:
                # Move command.

                # Get each 1-step move distance.
                dx = DX_DICT[current_direction]
                dy = DY_DICT[current_direction]

                for _ in range(command):
                    # Move 1-step forward every time.
                    new_x_coordinate, new_y_coordinate = (
                        current_x_coordinate + dx,
                        current_y_coordinate + dy
                    )

                    if (new_x_coordinate, new_y_coordinate) in obstacles_set:
                        # Break if the robot runs into an obstacle.
                        break

                    current_x_coordinate, current_y_coordinate = (
                        new_x_coordinate,
                        new_y_coordinate
                    )

                # Update maximum euclidean distance if needed.
                maximum_euclidean_distance = max(
                    maximum_euclidean_distance,
                    (current_x_coordinate ** 2) + (current_y_coordinate ** 2)
                )

        return maximum_euclidean_distance


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[4, -1, 3], []],
        [[4,-1,4,-2,4], [[2, 4]]],
        [[6, -1, -1, 6], [[0, 0]]],
    ]

    for testcase in testcases_list:
        print(sol.robotSim(*testcase))
