#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    const int s_length = ((int)strlen(s));
    char *answer_string_ptr = (
        (char*)malloc(sizeof(*answer_string_ptr) * (s_length + 1))
    );
    int write_index = 0;
    int max_read_index_steps = ((numRows - 1) << 1);

    if (NULL == answer_string_ptr) {
        return NULL;
    }
    else if (1 == numRows) {
        memcpy((void*)answer_string_ptr, (void*)s, s_length);

        answer_string_ptr[s_length] = '\0';

        return s;
    }

    for (int row_index = 0; row_index < numRows; ++row_index) {
        int read_index_steps = max_read_index_steps - (row_index << 1);

        if (0 == read_index_steps) {
            read_index_steps = max_read_index_steps;
        }

        for (int read_index = row_index; read_index < s_length;) {
            answer_string_ptr[write_index] = s[read_index];

            read_index += read_index_steps;

            if (max_read_index_steps != read_index_steps) {
                read_index_steps = max_read_index_steps - read_index_steps;
            }

            ++write_index;
        }
    }

    answer_string_ptr[s_length] = '\0';

    return answer_string_ptr;
}
