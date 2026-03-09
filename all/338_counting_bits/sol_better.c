#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    int *answer_array = (int*)malloc(sizeof(int) * (n + 1));
    answer_array[0] = 0;

    /*
     * Number n | Binary                 | Number of bit value 1
     *          | representation (4-bit) |
     * ---------|------------------------|----------------------
     *      0   | 0000                   | 0
     *      1   | 0001                   | 1
     *      2   | 0010                   | 1
     *      3   | 0011                   | 2
     *      4   | 0100                   | 1
     *      5   | 0101                   | 2
     *      6   | 0110                   | 2
     *      7   | 0111                   | 3
     *      8   | 1000                   | 1
     *      9   | 1001                   | 2
     *     10   | 1010                   | 2
     *     11   | 1011                   | 3
     *     12   | 1100                   | 2
     *     13   | 1101                   | 3
     *     14   | 1110                   | 3
     *     15   | 1111                   | 4
     *
     * By some observations, we can conclude the following rules:
     * 1. If n is 0, number of bit value 1 is 0. "This is base case".
     * 2. For any positive number n other than 0, as the number of bits
     *    in its binary representation is the number of bits in (n / 2)'s binary
     *    representation plus the LSB. LSB has only one bit, it's either 0 or 1.
     *    So the number of bit value 1 of n is the number of bit value 1 of
     *    (n / 2) plus the LSB bit value.
     *
     * This is a typical dynamic programming problem.
     */
    for (int i = 1; i <= n; ++i) {
        answer_array[i] = answer_array[(i - 1) >> 1] + (i & 1);
    }

    (*returnSize) = (n + 1);

    return answer_array;
}
