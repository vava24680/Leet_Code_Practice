#include <stdlib.h>

char findKthBit(int n, int k) {
    char answer_character = '\0';
    char *binary_string_ptr = (
        (char*)malloc(sizeof(*binary_string_ptr) * ((1 << n) - 1))
    );
    unsigned int current_string_length = 0;

    if (NULL == binary_string_ptr) {
        return '\0';
    }

    binary_string_ptr[0] = '0';

    for (int i = 1; i < n; ++i) {
        current_string_length = ((1U << i) - 1U);

        /* Construct the next binary string based on the rules. */
        binary_string_ptr[current_string_length] = '1';

        for (int j = 0; j < current_string_length; ++j) {
            binary_string_ptr[current_string_length + 1 + j] = (
                '1' - binary_string_ptr[current_string_length - 1 - j] + '0'
            );
        }
    }

    answer_character = binary_string_ptr[k - 1];

    free(binary_string_ptr);
    binary_string_ptr = NULL;

    return answer_character;
}
