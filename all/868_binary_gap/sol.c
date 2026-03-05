int binaryGap(int n) {
    unsigned int unsigned_n = ((unsigned int)n);
    int maximum_distance_between_adjacent_ones = 0;
    int previous_one_bit_position = -1;

    for (int bit_position = 0; unsigned_n; ++bit_position) {
        if (unsigned_n & 0x1) {
            if (
                (-1 != previous_one_bit_position)
                &&
                (
                    (bit_position - previous_one_bit_position)
                    >
                    maximum_distance_between_adjacent_ones
                )
            ) {
                maximum_distance_between_adjacent_ones = (
                    bit_position - previous_one_bit_position
                );
            }

            previous_one_bit_position = bit_position;
        }

        unsigned_n >>= 1;
    }

    return maximum_distance_between_adjacent_ones;
}
