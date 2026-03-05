#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;

    for (unsigned int i = 0; i < 32; ++i) {
        result <<= 1;
        result |= ((n >> i) & 1U);
    }

    return result;
}
