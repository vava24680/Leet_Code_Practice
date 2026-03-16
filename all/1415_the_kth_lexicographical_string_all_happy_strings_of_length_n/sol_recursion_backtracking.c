#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static const char * const PREVIOUS_CHARACTERS_AND_AVAILABLE_CHARACTERS_MAPPING_ARRAY[3] = {
    "bc",
    "ac",
    "ab",
};

void generateAllHappyStrings(
    char **happy_strings_array_ptr,
    char *current_happy_string_ptr,
    int * const current_happy_string_index_ptr,
    const char *candidate_characters_string_ptr,
    const int current_happy_string_length,
    const int happy_string_length
) {
    if (happy_string_length == current_happy_string_length) {
        strncpy(
            happy_strings_array_ptr[*current_happy_string_index_ptr],
            current_happy_string_ptr,
            happy_string_length
        );

        happy_strings_array_ptr[
            *current_happy_string_index_ptr
        ][
            happy_string_length
        ] = '\0';

        ++(*current_happy_string_index_ptr);

        return;
    }

    for (int i = 0; '\0' != (candidate_characters_string_ptr[i]); ++i) {
        current_happy_string_ptr[current_happy_string_length] = (
            candidate_characters_string_ptr[i]
        );
        generateAllHappyStrings(
            happy_strings_array_ptr,
            current_happy_string_ptr,
            current_happy_string_index_ptr,
            PREVIOUS_CHARACTERS_AND_AVAILABLE_CHARACTERS_MAPPING_ARRAY[
                candidate_characters_string_ptr[i] - 'a'
            ],
            current_happy_string_length + 1,
            happy_string_length
        );
    }
}

char* getHappyString(int n, int k) {
    if (n < 1) {
        return "";
    }

    int total_happy_strings_count = (3 * (1 << (n - 1)));
    int happy_string_index = 0;

    char *answer_string_ptr = NULL;
    char *data_blocks_array_ptr = NULL;
    char **happy_strings_array_ptr = NULL;

    if (k > total_happy_strings_count) {
        return "";
    }

    answer_string_ptr = (char*)malloc(sizeof(*answer_string_ptr) * (n + 1));
    data_blocks_array_ptr = (
        (char*)malloc(
            sizeof(*data_blocks_array_ptr) * (n + 1) * total_happy_strings_count
        )
    );
    happy_strings_array_ptr = (char**)malloc(
        sizeof(*happy_strings_array_ptr) * total_happy_strings_count
    );

    if (
        (NULL == answer_string_ptr)
        ||
        (NULL == data_blocks_array_ptr)
        ||
        (NULL == happy_strings_array_ptr)
    ) {
        free(answer_string_ptr);
        answer_string_ptr = NULL;

        free(data_blocks_array_ptr);
        data_blocks_array_ptr = NULL;

        free(happy_strings_array_ptr);
        happy_strings_array_ptr = NULL;

        return "";
    }

    for (int i = 0; i < total_happy_strings_count; ++i) {
        happy_strings_array_ptr[i] = (
            data_blocks_array_ptr + ((n + 1) * i)
        );
    }

    /* Generate all happy strings. */
    generateAllHappyStrings(
        happy_strings_array_ptr,
        answer_string_ptr,
        &happy_string_index,
        "abc",
        0,
        n
    );

    strncpy(answer_string_ptr, happy_strings_array_ptr[k - 1], n);

    answer_string_ptr[n] = '\0';

    return answer_string_ptr;
}
