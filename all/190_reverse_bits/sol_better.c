#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t result = n;
    uint32_t lower_bit_value = 0;
    uint32_t higher_bit_value = 0, higher_bit_index = 0;

    for (
        unsigned int lower_bit_index = 0;
        lower_bit_index < 16;
        ++lower_bit_index
    ) {
        higher_bit_index = 31 - lower_bit_index;
        lower_bit_value = ((result >> lower_bit_index) & (UINT32_C(1)));
        higher_bit_value = ((result >> higher_bit_index) & (UINT32_C(1)));

        if (lower_bit_value == higher_bit_value) {
            /* No need to swap two bits' values if there are the same. */
            continue;
        }

        /*
         * Swap two bits' values if there are different.
         * As bit value 1 will be changed to bit value 0 and vice versa,
         * we can use XOR operation to do that.
         */
        result ^= (
            ((UINT32_C(1)) << lower_bit_index)
            |
            ((UINT32_C(1)) << higher_bit_index)
        );
    }

    return result;
}
