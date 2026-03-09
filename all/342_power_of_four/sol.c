#define MAGIC_NUMBER (0x55555555)

bool isPowerOfFour(int n) {
    if ((n <= 0) || (0 != (n & (n - 1)))) {
        /*
         * Negitive numbers and numbers that are not power of two
         * cannot be power of four.
         */
        return false;
    }

    /*
     * Check if there is no any odd bit set, if check passed, return true.
     * Otherwises, return false.
     *
     * Reason: If a number is power of four, there exists only one bit is
     * set and the position of that bit must be a even number.
     */
    return 0 == (n & (~MAGIC_NUMBER));
}
