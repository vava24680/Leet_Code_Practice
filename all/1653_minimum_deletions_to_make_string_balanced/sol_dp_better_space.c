static inline int min(const int i1, const int i2) {
    return ((i1 < i2) ? i1 : i2);
}

int minimumDeletions(char* s) {
    int current_dp_state = 0;
    int previous_total_b_count = 0;

    for (int i = 0; '\0' != s[i]; ++i) {
        if ('b' == s[i]) {
            ++previous_total_b_count;
        }
        else if ('a' == s[i]) {
            current_dp_state = min(
                current_dp_state + 1,
                previous_total_b_count
            );
        }
    }

    return current_dp_state;
}
