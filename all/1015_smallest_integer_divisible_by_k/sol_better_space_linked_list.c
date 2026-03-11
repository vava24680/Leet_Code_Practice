int smallestRepunitDivByK(int k) {
    int current_n_length = 0;
    int slow_remainder = 0;
    int fast_remainder = 0;

    if (0 == (k & 0x1)) {
        /*
         * As n is a all 1-digit number, an odd number n cannot be factor
         * of an even number k, just return -1 directly.
         */
        return -1;
    }

    do {
        ++current_n_length;

        slow_remainder = ((slow_remainder * 10) + 1) % k;
        fast_remainder = ((fast_remainder * 10) + 1) % k;
        fast_remainder = ((fast_remainder * 10) + 1) % k;

        if ((slow_remainder == fast_remainder) && slow_remainder) {
            /*
             * If slow remainder and fast remainder are the same and the slow
             * remainder is greater than 0, it means remainder has circled back
             * and form a loop. It is impossible that there is n with all
             * digit 1 and that n is a multiple of k, so just return -1.
             */
            return -1;
        }
    } while (slow_remainder);

    return current_n_length;
}
