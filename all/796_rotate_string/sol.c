#include <stdbool.h>
#include <string.h>

bool rotateString(char* s, char* goal) {
    size_t s_length = strlen(s);
    size_t goal_length = strlen(goal);

    if (s_length != goal_length) {
        return false;
    }

    for (size_t base_index = 0; base_index < s_length; ++base_index) {
        if (
            (0 == strncmp(s + base_index, goal, s_length - base_index))
            &&
            (0 == strncmp(s, goal + s_length - base_index, base_index))
        ) {
            return true;
        }
    }

    return false;
}
