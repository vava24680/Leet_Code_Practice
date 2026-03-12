#include <stdbool.h>

bool isValid(char* s) {
    static const char close_open_brackets_mapping_array[128] = {
        [(int)')'] = '(',
        [(int)']'] = '[',
        [(int)'}'] = '{',
    };

    int stack_next_available_index = 0;
    char current_character = '\0', poped_character = '\0';

    for (int i = 0; '\0' != s[i]; ++i) {
        current_character = s[i];

        /* Use the original string s as the stack. */
        if (
            ('(' == current_character)
            ||
            ('[' == current_character)
            ||
            ('{' == current_character)
        ) {
            /* Push current open bracket character to stack. */
            s[stack_next_available_index] = current_character;
            ++stack_next_available_index;
        }
        else {
            /*
             * Check if current close bracket character can match the open
             * bracket character poped from the stack.
             */
            if (0 == stack_next_available_index) {
                /* Return false if stack is empty. */
                return false;
            }

            /* Pop a character from the stack. */
            poped_character = s[stack_next_available_index - 1];
            --(stack_next_available_index);

            if (
                close_open_brackets_mapping_array[(int)current_character]
                !=
                poped_character
            ) {
                /*
                 * Return false current close bracket character cannot pair
                 * with the open bracket character poped from the stack.
                 */
                return false;
            }
        }
    }

    return (0 == stack_next_available_index);
}
