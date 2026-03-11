#include <stdint.h>

int bitwiseComplement(int n) {
    if (0 == n) {
        return 1;
    }

    int n_bit_length = 0;
    unsigned int process_number = ((unsigned int)n);

    while (process_number) {
        ++n_bit_length;
        process_number >>= 1;
    }

    return n ^ ((int)(((UINT32_C(1)) << n_bit_length) - (UINT32_C(1))));
}
