#include <stdint.h>

bool hasAlternatingBits(int n) {
    /*
     * If a positive number n whose binary representation has alternating bits,
     * n ^ (n >> 1) results in a number whose binary representation is composed
     * by a bunch of consecutinve 1 from LSB.
     *
     * To test is a number n binary representation is composed by a bunch of
     * consecutinve 1 from LSB, we can check if n & (n + 1) is zero, if it is,
     * then binary representation of n is composed by a bunch of consecutinve
     * 1 from LSB.
     */
    unsigned int unsigned_n = ((unsigned int)n);

    return (0U == (unsigned_n & ((unsigned_n ^ (unsigned_n >> 1)) + 1U)));
}
