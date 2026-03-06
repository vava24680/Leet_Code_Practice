#include <stdlib.h>
#include <string.h>

static inline int min(const int i1, const int i2) {
    return ((i1 < i2) ? i1 : i2);
}

int minimumDeletions(char* s) {
    const size_t s_length = strlen(s);
    int minimum_deletions_count = 0;
    int *dp_array_ptr = (int*)calloc(s_length + 1U, sizeof(*dp_array_ptr));
    int previous_total_b_count = 0;

    if (NULL == dp_array_ptr) {
        return 0;
    }

    for (size_t i = 0; i < s_length; ++i) {
        if ('b' == s[i]) {
            dp_array_ptr[i + 1] = dp_array_ptr[i];
            ++previous_total_b_count;
        }
        else {
            dp_array_ptr[i + 1] = min(
                dp_array_ptr[i] + 1,
                previous_total_b_count
            );
        }
    }

    minimum_deletions_count = dp_array_ptr[s_length];

    free(dp_array_ptr);
    dp_array_ptr = NULL;

    return minimum_deletions_count;
}
