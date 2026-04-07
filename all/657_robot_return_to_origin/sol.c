#include <stdbool.h>

bool judgeCircle(char* moves) {
    /*
     * Use two variables to record horizontal and vertical movement amout.
     * If a 'U' movement instruction is used, increase vertical movement by 1.
     * If a 'D' movement instruction is used, decrease vertical movement by 1.
     * If a 'R' movement instruction is used, increase horizontal movement by 1.
     * If a 'L' movement instruction is used, decrease horizontal movement by 1.
     *
     * After all movement instructions, if vertical movement amount
     * and horizontal movement amount are all zero, it means the robot goes
     * back to the start position. Otherwises, it's not stay at the start
     * position.
     */
    int horizontal_movement_amount = 0;
    int vertical_movement_amount = 0;

    for (int i = 0; '\0' != (moves[i]); ++i) {
        switch (moves[i]) {
            case 'U':
                ++vertical_movement_amount;

                break;
            case 'D':
                --vertical_movement_amount;
                break;
            case 'R':
                ++horizontal_movement_amount;

                break;
            case 'L':
                --horizontal_movement_amount;

                break;
            default:
                return false;
        }
    }

    return (
        (0 == vertical_movement_amount)
        &&
        (0 == horizontal_movement_amount)
    );
}
