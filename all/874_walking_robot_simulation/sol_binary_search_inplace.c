#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
} DirectionEnum;

static const int DX_ARRAY[] = {0, 0, -1, 1};
static const int DY_ARRAY[] = {1, -1, 0, 0};

static inline int max(const int i1, const int i2) {
    return ((i1 > i2) ? i1 : i2);
}

static int compareFunction(const void *p1, const void *p2) {
    const int *coordinate_array_1_ptr = (*((const int**)p1));
    const int *coordinate_array_2_ptr = (*((const int**)p2));

    if ((coordinate_array_1_ptr[0]) == (coordinate_array_2_ptr[0])) {
        return (
            (
                (coordinate_array_1_ptr[1])
                >
                (coordinate_array_2_ptr[1])
            )
            -
            (
                (coordinate_array_1_ptr[1])
                <
                (coordinate_array_2_ptr[1])
            )
        );
    }

    return (
        (
            (coordinate_array_1_ptr[0])
            >
            (coordinate_array_2_ptr[0])
        )
        -
        (
            (coordinate_array_1_ptr[0])
            <
            (coordinate_array_2_ptr[0])
        )
    );
}

static DirectionEnum determineNewDirection(
    const DirectionEnum current_direction,
    int turning_value
) {
    if (UP == current_direction) {
        return ((-1 == turning_value) ? RIGHT : LEFT);
    }
    else if (DOWN == current_direction) {
        return ((-1 == turning_value) ? LEFT : RIGHT);
    }
    else if (LEFT == current_direction) {
        return ((-1 == turning_value) ? UP : DOWN);
    }

    return ((-1 == turning_value) ? DOWN : UP);
}

static bool isObstacle(
    const int x_coordinate,
    const int y_coordinate,
    const int obstacles_count,
    int** obstacles_coordinates_array_ptr
) {
    int left_index = 0, right_index = obstacles_count, middle_index = 0;

    /*
     * Use binary search to find the first obstacle whose coordinate is larger
     * than or equal the current coordinate.
     */
    while (left_index < right_index) {
        middle_index = (left_index + ((right_index - left_index) >> 1));

        if (
            (
                (obstacles_coordinates_array_ptr[middle_index][0])
                <
                x_coordinate
            )
            ||
            (
                (
                    x_coordinate
                    ==
                    (obstacles_coordinates_array_ptr[middle_index][0])
                )
                &&
                (
                    (obstacles_coordinates_array_ptr[middle_index][1])
                    <
                    y_coordinate
                )
            )
        ) {
            left_index = (middle_index + 1);
        }
        else {
            right_index = middle_index;
        }
    }

    if (
        (left_index == obstacles_count)
        ||
        (
            x_coordinate
            !=
            (obstacles_coordinates_array_ptr[left_index][0])
        )
        ||
        (
            y_coordinate
            !=
            (obstacles_coordinates_array_ptr[left_index][1])
        )
    ) {
        /* Return false if target obstacle does not exist. */
        return false;
    }

    return true;
}

int robotSim(
    int* commands,
    int commandsSize,
    int** obstacles,
    int obstaclesSize,
    int* obstaclesColSize
) {
    int maximum_euclidean_distance = -1;
    int current_x_coordinate = 0, current_y_coordinate = 0;
    int dx = 0, dy = 0, new_x_coordinate = 0, new_y_coordinate = 0;
    DirectionEnum current_direction = UP;

    /* Sort the obstacles coordinates in the ascending order. */
    qsort(
        (void*)obstacles,
        obstaclesSize,
        sizeof(*obstacles),
        &compareFunction
    );

    for (int i = 0; i < commandsSize; ++i) {
        if ((commands[i]) < 0) {
            /* Turn command. */

            /* Determine new direction. */
            current_direction = determineNewDirection(
                current_direction,
                commands[i]
            );
        }
        else {
            /* Move command. */

            /* Get each 1-step move distance. */
            dx = DX_ARRAY[current_direction];
            dy = DY_ARRAY[current_direction];

            for (int j = 0; j < (commands[i]); ++j) {
                /* Move 1-step forward every time. */
                new_x_coordinate = (current_x_coordinate + dx);
                new_y_coordinate = (current_y_coordinate + dy);

                if (
                    isObstacle(
                        new_x_coordinate,
                        new_y_coordinate,
                        obstaclesSize,
                        obstacles
                    )
                ) {
                    /* Break if the robot runs into an obstacle. */
                    break;
                }

                current_x_coordinate = new_x_coordinate;
                current_y_coordinate = new_y_coordinate;
            }

            /* Update maximum euclidean distance if needed. */
            maximum_euclidean_distance = max(
                maximum_euclidean_distance,
                (current_x_coordinate * current_x_coordinate)
                +
                (current_y_coordinate * current_y_coordinate)
            );
        }
    }

    return maximum_euclidean_distance;
}
