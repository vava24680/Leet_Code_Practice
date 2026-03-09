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
     * 2. If n is odd, number of bit value 1 is 1 plus the result of (n - 1).
     *    This is trivial proven by the n is a result of (n - 1) + 1,
     *    and (n - 1) is even so the bit 0's value must be 0, plus 1 won't
     *    cause carry, so the number of bit value 1 in n is one more than
     *    (n - 1).
     * 3. If n is even, number of bit value 1 is the result of ((n - 1) / 2 + 1).
     *    This can also be proven by the n is a result of (n - 1) + 1,
     *    and (n - 1) is odd so the bit 0's value must be 1, plus 1 will cause
     *    carry, if we ignore bit 0, the rest of addtion will be
     *    ((n - 1) / 2) + 1, so the number of bit value 1 in n is the number of
     *    bit value 1 in ((n - 1) / 2 + 1).
     *
     * This is a typical dynamic programming problem.
     */
    for (int i = 1; i <= n; ++i) {
        if (1 == (i & 1)) {
            answer_array[i] = answer_array[i - 1] + 1;
        }
        else {
            answer_array[i] = answer_array[((i - 1) >> 1) + 1];
        }
    }

    (*returnSize) = (n + 1);

    return answer_array;
}
