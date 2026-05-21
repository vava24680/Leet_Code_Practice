#include <stdint.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int countSetBit(uint64_t x) {
    x = (
        (x & (UINT64_C(0x5555555555555555)))
        +
        ((x >> 1) & (UINT64_C(0x5555555555555555)))
    );
    x = (
        (x & (UINT64_C(0x3333333333333333)))
        +
        ((x >> 2) & (UINT64_C(0x3333333333333333)))
    );
    x = (
        (x & (UINT64_C(0x0F0F0F0F0F0F0F0F)))
        +
        ((x >> 4) & (UINT64_C(0x0F0F0F0F0F0F0F0F)))
    );
    x = (
        (x & (UINT64_C(0x00FF00FF00FF00FF)))
        +
        ((x >> 8) & (UINT64_C(0x00FF00FF00FF00FF)))
    );
    x = (
        (x & (UINT64_C(0x0000FFFF0000FFFF)))
        +
        ((x >> 16) & (UINT64_C(0x0000FFFF0000FFFF)))
    );
    x = (
        (x & (UINT64_C(0x00000000FFFFFFFF)))
        +
        ((x >> 32) & (UINT64_C(0x00000000FFFFFFFF)))
    );

    return ((int)x);
}

int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int *answer_array_ptr = (int*)malloc(sizeof(*answer_array_ptr) * ASize);
    uint64_t bitmap_1 = UINT64_C(0), bitmap_2 = UINT64_C(0);

    for (int i = 0; i < ASize; ++i) {
        /* Set corresponding bit to 1 int bitmap 1. */
        bitmap_1 |= ((UINT64_C(1)) << (A[i]));

        /* Set corresponding bit to 1 int bitmap 2. */
        bitmap_2 |= ((UINT64_C(1)) << (B[i]));

        /*
         * The count of set bits in the (bitmap_1 & bitmap_2) is the count
         * of numbers that shows in both of array A and array B.
         */
        answer_array_ptr[i] = countSetBit(bitmap_1 & bitmap_2);
    }

    (*returnSize) = ASize;

    return answer_array_ptr;
}
