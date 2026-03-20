#include <stdbool.h>

bool checkStraightLine(
    int** coordinates,
    int coordinatesSize,
    int* coordinatesColSize
) {
    int first_point_x_index = coordinates[0][0];
    int first_point_y_index = coordinates[0][1];
    int second_point_x_index = coordinates[1][0];
    int second_point_y_index = coordinates[1][1];

    for (int i = 2; i < coordinatesSize; ++i) {
        int current_x_index = coordinates[i][0];
        int current_y_index = coordinates[i][1];

        if (
            (
                (current_y_index - first_point_y_index)
                *
                (current_x_index - second_point_x_index)
            )
            !=
            (
                (current_y_index - second_point_y_index)
                *
                (current_x_index - first_point_x_index)
            )
        ) {
            return false;
        }
    }

    return true;
}
