#include <stdbool.h>
#include <stdlib.h>

bool hasAllCodes(char* s, int k) {
    const int binary_string_value_bitmask = ((1 << k) - 1);

    bool *substrings_showed_array_ptr = (
        (bool*)calloc(1 << k, sizeof(*substrings_showed_array_ptr))
    );
    bool answer = true;
    int window_right_index = 0;
    int current_binary_string_value = 0;

    if (NULL == substrings_showed_array_ptr) {
        return false;
    }

    for (
        int window_right_index = 0;
        '\0' != s[window_right_index];
        ++window_right_index
    ) {
        current_binary_string_value = (
            (current_binary_string_value << 1) | (s[window_right_index] - '0')
        );

        if (window_right_index >= (k - 1)) {
            current_binary_string_value &= binary_string_value_bitmask;
            substrings_showed_array_ptr[current_binary_string_value] = true;
        }
    }

    for (int i = 0; i < (1 << k); ++i) {
        if (!substrings_showed_array_ptr[i]) {
            answer = false;

            break;
        }
    }

    free(substrings_showed_array_ptr);
    substrings_showed_array_ptr = NULL;

    return answer;
}
