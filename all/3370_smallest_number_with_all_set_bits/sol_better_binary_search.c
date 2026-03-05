int smallestNumber(int n) {
    unsigned long long left_bits_length = 1ULL;
    unsigned long long right_bits_length = 32ULL;
    unsigned long long middle_bits_length = 0ULL;

    while (left_bits_length < right_bits_length) {
        middle_bits_length = (
            left_bits_length
            +
            ((right_bits_length - left_bits_length) >> 1)
        );

        if ((1ULL << middle_bits_length) <= ((unsigned long long)n)) {
            left_bits_length = middle_bits_length + 1ULL;
        }
        else {
            right_bits_length = middle_bits_length;
        }
    }

    return (int)((1ULL << left_bits_length) - 1ULL);
}
