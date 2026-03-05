static inline int min(const int i1, const int i2) {
    return ((i1 < i2) ? i1 : i2);
}

int minOperations(char* s) {
    /* For starting bit is 1 case. */
    int current_expected_bit_1 = 1;
    int operations_count_1 = 0;

    /* For starting bit is 0 case. */
    int current_expected_bit_2 = 0;
    int operations_count_2 = 0;

    for (int i = 0; '\0' != s[i]; ++i) {
        if (('0' + current_expected_bit_1) != s[i]) {
            ++operations_count_1;
        }

        if (('0' + current_expected_bit_2) != s[i]) {
            ++operations_count_2;
        }

        current_expected_bit_1 ^= 1;
        current_expected_bit_2 ^= 1;
    }

    return min(operations_count_1, operations_count_2);
}
