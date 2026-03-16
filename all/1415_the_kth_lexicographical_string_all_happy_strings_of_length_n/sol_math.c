#include <stddef.h>
#include <stdlib.h>

static const char* const PREVIOUS_CHARACTERS_AND_AVAILABLE_CHARACTERS_MAPPING_ARRAY[] = {
    "bc",
    "ac",
    "ab",
};

char* getHappyString(int n, int k) {
    if (n < 1) {
        return "";
    }

    char *answer_string_ptr = NULL;
    int total_happy_strings_count = (3 * (1 << (n - 1)));
    int happy_strings_count_in_a_group = (total_happy_strings_count / 3);
    int next_write_index = 0;
    int happy_string_current_index, happy_string_new_index = (k - 1);

    if (k > total_happy_strings_count) {
        return "";
    }

    answer_string_ptr = (char*)malloc(sizeof(*answer_string_ptr) * (n + 1));

    if (NULL == answer_string_ptr) {
        return "";
    }

    /* Set the first character of the happy string. */
    happy_string_current_index = (
        happy_string_new_index / happy_strings_count_in_a_group
    );
    happy_string_new_index = (
        happy_string_new_index % happy_strings_count_in_a_group
    );
    answer_string_ptr[next_write_index++] = ('a' + happy_string_current_index);
    happy_strings_count_in_a_group >>= 1;

    /* Set the rest of characters in the happy string. */
    while (happy_strings_count_in_a_group) {
        happy_string_current_index = (
            happy_string_new_index / happy_strings_count_in_a_group
        );
        happy_string_new_index %= happy_strings_count_in_a_group;
        answer_string_ptr[next_write_index] = (
            PREVIOUS_CHARACTERS_AND_AVAILABLE_CHARACTERS_MAPPING_ARRAY[
                answer_string_ptr[next_write_index - 1] - 'a'
            ][
                happy_string_current_index
            ]
        );
        ++next_write_index;

        happy_strings_count_in_a_group >>= 1;
    }

    answer_string_ptr[n] = '\0';

    return answer_string_ptr;
}
