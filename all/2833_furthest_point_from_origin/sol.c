#include <stdlib.h>

int furthestDistanceFromOrigin(char* moves) {
    int left_moves_count = 0;
    int right_moves_count = 0;
    int undecided_direction_moves_count = 0;

    for (int i = 0; '\0' != (moves[i]); ++i) {
        if ('L' == (moves[i])) {
            ++left_moves_count;
        }
        else if ('R' == (moves[i])) {
            ++right_moves_count;
        }
        else {
            ++undecided_direction_moves_count;
        }
    }

    return (
        abs(left_moves_count - right_moves_count)
        +
        undecided_direction_moves_count
    );
}
