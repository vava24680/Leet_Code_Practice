#include <stdlib.h>
#include <string.h>

char* decodeCiphertext(char* encodedText, int rows) {
    const int encoded_text_string_length = strlen(encodedText);
    const int ROWS_NUMBER = rows;
    const int COLUMNS_NUMBER = (encoded_text_string_length / ROWS_NUMBER);

    char *answer_string_ptr = (
        (char*)malloc(
            sizeof(*answer_string_ptr) * (encoded_text_string_length + 1)
        )
    );
    int last_non_space_character_index = -1;
    int current_answer_string_length = 0;
    int row_index = 0, column_index = 0, one_dimension_index = 0;

    for (
        int start_column_index = 0;
        start_column_index < COLUMNS_NUMBER;
        ++start_column_index
    ) {
        row_index = 0;
        column_index = start_column_index;

        while ((row_index < ROWS_NUMBER) && (column_index < COLUMNS_NUMBER)) {
            one_dimension_index = ((row_index * COLUMNS_NUMBER) + column_index);

            answer_string_ptr[current_answer_string_length] = (
                encodedText[one_dimension_index]
            );

            ++current_answer_string_length;
            ++row_index;
            ++column_index;
        }
    }

    last_non_space_character_index = (current_answer_string_length - 1);

    /* Get rid of all trailing spaces. */
    while (
        (last_non_space_character_index >= 0)
        &&
        (' ' == (answer_string_ptr[last_non_space_character_index]))
    ) {
        --last_non_space_character_index;
    }

    /* Add null-terminated character to the end of answer string. */
    answer_string_ptr[last_non_space_character_index + 1] = '\0';

    return answer_string_ptr;
}
