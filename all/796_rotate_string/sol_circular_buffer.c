#include <stdbool.h>
#include <string.h>

bool rotateString(char* s, char* goal) {
    size_t s_length = strlen(s);
    size_t goal_length = strlen(goal);
    bool is_matched = false;

    if (s_length != goal_length) {
        return false;
    }

    for (size_t first_index = 0; first_index < s_length; ++first_index) {
        is_matched = true;

        for (int i = 0; i < s_length; ++i) {
            if ((goal[i]) != (s[(first_index + i) % s_length])) {
                is_matched = false;

                break;
            }
        }

        if (is_matched) {
            return true;
        }
    }

    return false;
}
