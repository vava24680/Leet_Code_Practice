#include <stdint.h>

int findComplement(int num) {
    int num_bit_length = 0;
    unsigned int process_num = ((unsigned int)num);

    while (process_num) {
        ++num_bit_length;
        process_num >>= 1;
    }

    return num ^ ((int)(((UINT32_C(1)) << num_bit_length) - (UINT32_C(1))));
}
