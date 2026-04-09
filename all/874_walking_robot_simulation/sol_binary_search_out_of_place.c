#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
} DirectionEnum;

typedef struct {
    int x_coordinate;
    int y_coordinate;
} CoordinateST;

static const int DX_ARRAY[] = {0, 0, -1, 1};
static const int DY_ARRAY[] = {1, -1, 0, 0};

static inline int max(const int i1, const int i2) {
    return ((i1 > i2) ? i1 : i2);
}

static int compareFunction(const void *p1, const void *p2) {
    const CoordinateST *coordinate_st_1_ptr = ((const CoordinateST*)p1);
    const CoordinateST *coordinate_st_2_ptr = ((const CoordinateST*)p2);

    if (
        (coordinate_st_1_ptr->x_coordinate)
        ==
        (coordinate_st_2_ptr->x_coordinate)
    ) {
        return (
            (
                (coordinate_st_1_ptr->y_coordinate)
                >
                (coordinate_st_2_ptr->y_coordinate)
            )
            -
            (
                (coordinate_st_1_ptr->y_coordinate)
                <
                (coordinate_st_2_ptr->y_coordinate)
            )
        );
    }

    return (
        (
            (coordinate_st_1_ptr->x_coordinate)
            >
            (coordinate_st_2_ptr->x_coordinate)
        )
        -
        (
            (coordinate_st_1_ptr->x_coordinate)
            <
            (coordinate_st_2_ptr->x_coordinate)
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
    const CoordinateST * const obstacles_coordinates_st_array_ptr,
    const int obstacles_count
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
                ((obstacles_coordinates_st_array_ptr[middle_index]).x_coordinate)
                <
                x_coordinate
            )
            ||
            (
                (
                    x_coordinate
                    ==
                    (obstacles_coordinates_st_array_ptr[middle_index].x_coordinate)
                )
                &&
                (
                    ((obstacles_coordinates_st_array_ptr[middle_index]).y_coordinate)
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
            ((obstacles_coordinates_st_array_ptr[left_index]).x_coordinate)
        )
        ||
        (
            y_coordinate
            !=
            ((obstacles_coordinates_st_array_ptr[left_index]).y_coordinate)
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
    CoordinateST *obstacles_coordinates_st_array_ptr = (
        (CoordinateST*)malloc(
            sizeof(*obstacles_coordinates_st_array_ptr)
            *
            obstaclesSize
        )
    );
    DirectionEnum current_direction = UP;

    /* Add each obstacle coordinate to the array. */
    for (int i = 0; i < obstaclesSize; ++i) {
        ((obstacles_coordinates_st_array_ptr[i]).x_coordinate) = (
            obstacles[i][0]
        );
        ((obstacles_coordinates_st_array_ptr[i]).y_coordinate) = (
            obstacles[i][1]
        );
    }

    /* Sort the obstacles values array in the ascending order. */
    qsort(
        (void*)obstacles_coordinates_st_array_ptr,
        obstaclesSize,
        sizeof(*obstacles_coordinates_st_array_ptr),
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
                        obstacles_coordinates_st_array_ptr,
                        obstaclesSize
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

    free(obstacles_coordinates_st_array_ptr);
    obstacles_coordinates_st_array_ptr = NULL;

    return maximum_euclidean_distance;
}
