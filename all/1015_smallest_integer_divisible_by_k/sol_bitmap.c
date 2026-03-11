#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define BITMAP_BITS_COUNT (64)

void setBitInBitmapArray(
    const int bit,
    const int bitmap_array_size,
    uint64_t * const bitmap_array_ptr
) {
    if ((bit / (BITMAP_BITS_COUNT)) >= bitmap_array_size) {
        return;
    }

    bitmap_array_ptr[bit / BITMAP_BITS_COUNT] |= (
        (UINT64_C(1)) << ((unsigned int)(bit % BITMAP_BITS_COUNT))
    );
}

bool testBitInBitmapArray(
    const int bit,
    const int bitmap_array_size,
    const uint64_t * const bitmap_array_ptr
) {
    if ((bit / (BITMAP_BITS_COUNT)) >= bitmap_array_size) {
        return false;
    }

    return (
        (
            bitmap_array_ptr[bit / BITMAP_BITS_COUNT]
            &
            ((UINT64_C(1)) << ((unsigned int)(bit % BITMAP_BITS_COUNT)))
        )
        >
        (UINT64_C(0))
    );
}

int smallestRepunitDivByK(int k) {
    if (0 == (k & 0x1)) {
        /*
         * As n is a all 1-digit number, an odd number n cannot be factor
         * of an even number k, just return -1 directly.
         */
        return -1;
    }

    int bitmap_array_size = (
        (k + 1 + ((BITMAP_BITS_COUNT) - 1)) / (BITMAP_BITS_COUNT)
    );
    uint64_t *remainders_bitmap_array_ptr = (uint64_t*)calloc(
        bitmap_array_size,
        sizeof(*remainders_bitmap_array_ptr)
    );
    int current_n_length = 0;
    int current_n_remainder = 0;

    do {
        ++current_n_length;

        /*
         * Use congruence modulo compute the remainder of current n modulo
         * by k by using the remainder of the previous n modulo by k.
         */
        current_n_remainder = ((current_n_remainder * 10) + 1) % k;

        if (
            testBitInBitmapArray(
                current_n_remainder,
                bitmap_array_size,
                &(remainders_bitmap_array_ptr[0])
            )
        ) {
            /*
             * If the corresponding bit of current remainder of current n
             * modulo by k has been set in the remainders' bitmap, it means
             * remainder has circled back and form a loop, it is impossible
             * to find a number n with all digit 1 that is a multiple of k,
             * so just return -1.
             */
            current_n_length = -1;

            break;
        }

        /* Set corresponding bit of current remainder in the remainders' bitmap. */
        setBitInBitmapArray(
            current_n_remainder,
            bitmap_array_size,
            &(remainders_bitmap_array_ptr[0])
        );
    } while (0 != current_n_remainder);

    free(remainders_bitmap_array_ptr);

    remainders_bitmap_array_ptr = NULL;

    return current_n_length;
}
