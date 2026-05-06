#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

bool rotateString(char* s, char* goal) {
    size_t s_length = strlen(s);
    size_t goal_length = strlen(goal);
    char *concatenated_string_ptr = NULL;
    bool result = true;

    if (s_length != goal_length) {
        return false;
    }

    concatenated_string_ptr = (
        (char*)malloc((sizeof(*concatenated_string_ptr) * s_length * 2) + 1)
    );

    memcpy(concatenated_string_ptr, s, s_length);
    memcpy(concatenated_string_ptr + s_length, s, s_length);

    concatenated_string_ptr[s_length << 1] = '\0';

    result = (NULL != strstr(concatenated_string_ptr, goal));

    free(concatenated_string_ptr);
    concatenated_string_ptr = NULL;

    return result;
}
