#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t result = n;

    result = (
        ((result & UINT32_C(0xFFFF0000)) >> UINT32_C(16))
        |
        ((result & UINT32_C(0x0000FFFF)) << UINT32_C(16))
    );
    result = (
        ((result & UINT32_C(0xFF00FF00)) >> UINT32_C(8))
        |
        ((result & UINT32_C(0x00FF00FF)) << UINT32_C(8))
    );
    result = (
        ((result & UINT32_C(0xF0F0F0F0)) >> UINT32_C(4))
        |
        ((result & UINT32_C(0x0F0F0F0F)) << UINT32_C(4))
    );
    result = (
        ((result & UINT32_C(0xCCCCCCCC)) >> UINT32_C(2))
        |
        ((result & UINT32_C(0x33333333)) << UINT32_C(2))
    );
    result = (
        ((result & UINT32_C(0xAAAAAAAA)) >> UINT32_C(1))
        |
        ((result & UINT32_C(0x55555555)) << UINT32_C(1))
    );

    return result;
}
