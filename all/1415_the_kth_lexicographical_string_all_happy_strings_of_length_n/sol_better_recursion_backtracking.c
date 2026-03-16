#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static const char * const PREVIOUS_CHARACTERS_AND_AVAILABLE_CHARACTERS_MAPPING_ARRAY[] = {
    "bc",
    "ac",
    "ab",
};

bool generateAllHappyStrings(
    char *current_happy_string_ptr,
    int * const current_happy_string_index_ptr,
    const char *candidate_characters_string_ptr,
    const int current_happy_string_length,
    const int happy_string_length,
    const int target_happy_string_index
) {
    if (happy_string_length == current_happy_string_length) {
        if (target_happy_string_index == (*current_happy_string_index_ptr)) {
            /* Return true if the target happy string is generated completely. */
            return true;
        }

        ++(*current_happy_string_index_ptr);

        return false;
    }

    for (int i = 0; '\0' != (candidate_characters_string_ptr[i]); ++i) {
        current_happy_string_ptr[current_happy_string_length] = (
            candidate_characters_string_ptr[i]
        );
        if (
            generateAllHappyStrings(
                current_happy_string_ptr,
                current_happy_string_index_ptr,
                PREVIOUS_CHARACTERS_AND_AVAILABLE_CHARACTERS_MAPPING_ARRAY[
                    candidate_characters_string_ptr[i] - 'a'
                ],
                current_happy_string_length + 1,
                happy_string_length,
                target_happy_string_index
            )
        ) {
            return true;
        }
    }

    return false;
}

char* getHappyString(int n, int k) {
    if (n < 1) {
        return "";
    }

    int total_happy_strings_count = (3 * (1 << (n - 1)));
    int happy_string_index = 0;

    char *answer_string_ptr = NULL;

    if (k > total_happy_strings_count) {
        return "";
    }

    answer_string_ptr = (char*)malloc(sizeof(*answer_string_ptr) * (n + 1));

    if (NULL == answer_string_ptr) {
        return "";
    }

    /* Generate the target happy string. */
    generateAllHappyStrings(
        answer_string_ptr,
        &happy_string_index,
        "abc",
        0,
        n,
        k - 1
    );

    answer_string_ptr[n] = '\0';

    return answer_string_ptr;
}
