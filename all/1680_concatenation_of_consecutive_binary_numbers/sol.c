const unsigned long long MODULO_NUMBER = 1000000007ULL;

int concatenatedBinary(int n) {
    unsigned long long answer = 0ULL;
    int left_shift_bits_count = 0;

    for (int i = 1; i <= n; ++i) {
        if (0 == (i & (i - 1))) {
            /*
             * If current number is power of 2, we need to increase left shift
             * bits count by 1 to get correct left shift bits count.
             */
            ++left_shift_bits_count;
        }

        /*
         * Treat concatenation as the original number is left shifted by
         * some bits and do a addition later.
         */
        answer = (
            ((answer << left_shift_bits_count) + ((unsigned long long)i))
            %
            MODULO_NUMBER
        );
    }

    return (int)answer;
}
