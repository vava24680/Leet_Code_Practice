#include <limits.h>

static inline int min(const int i1, const int i2) {
    return ((i1 < i2) ? i1 : i2);
}

int minimumDeletions(char* s) {
    int minimum_deletions_count = INT_MAX;
    int total_a_count = 0;
    int previous_total_b_count = 0, previous_total_a_count = 0;
    int s_length = 0;

    /* Count how many a in the string s first. */
    for (s_length = 0; '\0' != s[s_length]; ++s_length) {
        if ('a' != s[s_length]) {
            continue;
        }

        ++total_a_count;
    }

    /*
     * Try every cut index, from 0 to string s length.
     *
     * For every cut index i, the string is splitted into parts: s[:i] and
     * s[i:].
     * We need to remove all the character b in the s[:i] and remove all the
     * character a in the s[i:] to make the string s balanced under current
     * cutting.
     *
     * To compute the count of the character a in the s[i:], it is the
     * difference of the count of the character a in the string s minus
     * the count of the charactera in the s[:i], so we can use prefix sum
     * to avoid repreated counting.
     */
    for (int cut_index = 0; cut_index < s_length; ++cut_index) {
        minimum_deletions_count = min(
            minimum_deletions_count,
            previous_total_b_count + (total_a_count - previous_total_a_count)
        );

        if ('b' == s[cut_index]) {
            ++previous_total_b_count;
        }
        else if ('a' == s[cut_index]) {
            ++previous_total_a_count;
        }
    }

    /* The last cut index is the length of the string s. */
    minimum_deletions_count = min(
        minimum_deletions_count,
        previous_total_b_count + (total_a_count - previous_total_a_count)
    );

    return minimum_deletions_count;
}
