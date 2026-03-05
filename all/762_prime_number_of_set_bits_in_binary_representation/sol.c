#include <stdbool.h>

static int countSetBits(int n) {
    int set_bits_count = 0;

    while (n) {
        ++set_bits_count;
        n &= (n - 1);
    }

    return set_bits_count;
}

static bool isPrimeNumber(const int n) {
    static const bool is_prirme_number_array[] = {
        [0] = false, [1] = false, [2] = true, [3] = true, [4] = false,
        [5] = true, [6] = false, [7] = true, [8] = false, [9] = false,
        [10] = false, [11] = true, [12] = false, [13] = true, [14] = false,
        [15] = false, [16] = false, [17] = true, [18] = false, [19] = true,
        [21] = false,
    };

    if (
        (n < 0)
        ||
        (
            n
            >=
            (
                (sizeof(is_prirme_number_array))
                /
                (sizeof(is_prirme_number_array[0]))
            )
        )
    ) {
        return false;
    }

    return is_prirme_number_array[n];
}

int countPrimeSetBits(int left, int right) {
    int count = 0;

    for (int number = left; number <= right; ++number) {
        if (isPrimeNumber(countSetBits(number))) {
            ++count;
        }
    }

    return count;
}
