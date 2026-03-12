#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct {
    char *characters_array_ptr;
    int array_size;
    int next_available_index;
} OpenBracketStackST;

static bool pushAnOpenBracketCharacterToStack(
    OpenBracketStackST* open_brackets_stack_st_ptr,
    const char open_bracket_character
) {
    char *tmp_ptr = NULL;
    int new_array_size = 0;

    if (
        (open_brackets_stack_st_ptr->next_available_index)
        >=
        (open_brackets_stack_st_ptr->array_size)
    ) {
        if (0 == (open_brackets_stack_st_ptr->array_size)) {
            new_array_size = 4;
        }
        else {
            new_array_size = ((open_brackets_stack_st_ptr->array_size) << 1);
        }

        tmp_ptr = (char*)realloc(
            open_brackets_stack_st_ptr->characters_array_ptr,
            sizeof(*(open_brackets_stack_st_ptr->characters_array_ptr))
            *
            new_array_size
        );

        if (NULL == tmp_ptr) {
            /* Let caller decides what to do if memory allocation fails. */
            return false;
        }

        (open_brackets_stack_st_ptr->characters_array_ptr) = tmp_ptr;
        (open_brackets_stack_st_ptr->array_size) = new_array_size;
    }

    (open_brackets_stack_st_ptr->characters_array_ptr)[
        open_brackets_stack_st_ptr->next_available_index
    ] = open_bracket_character;
    ++(open_brackets_stack_st_ptr->next_available_index);

    return true;
}

bool isValid(char* s) {
    static const char close_open_brackets_mapping_array[128] = {
        [(int)')'] = '(',
        [(int)']'] = '[',
        [(int)'}'] = '{',
    };

    OpenBracketStackST open_brackets_stack_st = {
        .characters_array_ptr = NULL,
        .array_size = 0,
        .next_available_index = 0,
    };
    char current_character = '\0', poped_character = '\0';
    bool result = false;

    for (int i = 0; '\0' != s[i]; ++i) {
        current_character = s[i];

        if (
            ('(' == current_character)
            ||
            ('[' == current_character)
            ||
            ('{' == current_character)
        ) {
            /* Push current open bracket character to stack. */
            if (
                !pushAnOpenBracketCharacterToStack(
                    &open_brackets_stack_st,
                    current_character
                )
            ) {
                /* Teminate if pushing a open bracket character to stack fails. */
                result = false;

                goto FINAL_CLEANUP;
            }
        }
        else {
            /*
             * Check if current close bracket character can match the open
             * bracket character poped from the stack.
             */
            if (0 == (open_brackets_stack_st.next_available_index)) {
                /* Terminate if stack is empty. */
                result = false;

                goto FINAL_CLEANUP;
            }

            /* Pop a character from the stack. */
            poped_character = (
                (open_brackets_stack_st.characters_array_ptr)[
                    (open_brackets_stack_st.next_available_index) - 1
                ]
            );
            --(open_brackets_stack_st.next_available_index);

            if (
                close_open_brackets_mapping_array[(int)current_character]
                !=
                poped_character
            ) {
                /*
                 * Terminate if current close bracket character cannot pair
                 * with the open bracket character poped from the stack.
                 */
                result = false;

                goto FINAL_CLEANUP;
            }
        }
    }

    result = (0 == (open_brackets_stack_st.next_available_index));

FINAL_CLEANUP:
    free(open_brackets_stack_st.characters_array_ptr);
    open_brackets_stack_st.characters_array_ptr = NULL;

    return result;
}
