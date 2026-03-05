#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool hasAllCodes(char* s, int k) {
    int carry_bit_value = 1, old_current_bit_value = 0;
    bool answer = true;
    char *current_binary_string_ptr = (char*)malloc(
        sizeof(*current_binary_string_ptr) * (k + 1)
    );

    if (NULL == current_binary_string_ptr) {
        return false;
    }

    /* Initialize binary string. */
    current_binary_string_ptr[k] = '\0';
    memset((void*)current_binary_string_ptr, '1', k);

    for (int i = 0; i < (1 << k); ++i) {
        /* Construct current binary string by simulating addition. */
        carry_bit_value = 1;

        for (int bit_index = k - 1; bit_index >= 0; --bit_index) {
            old_current_bit_value = (
                current_binary_string_ptr[bit_index] - '0'
            );
            current_binary_string_ptr[bit_index] = (
                '0' + (carry_bit_value ^ old_current_bit_value)
            );

            if (!(old_current_bit_value && carry_bit_value)) {
                break;
            }

            carry_bit_value = 1;
        }

        if (NULL == strstr(s, current_binary_string_ptr)) {
            answer = false;

            break;
        }
    }

    free(current_binary_string_ptr);
    current_binary_string_ptr = NULL;

    return answer;
}
