char findKthBit(int n, int k) {
    int invert_count = 0;
    int current_string_length = 0;

    for (; n > 1; --n) {
        current_string_length = ((1 << n) - 1);

        if ((k - 1) == (current_string_length >> 1)) {
            /* Need to consider invert count before return. */
            return ((invert_count & 0x1) ? '0' : '1');
        }
        else if ((k - 1) > (current_string_length >> 1)) {
            /* Increase invert count by 1. */
            ++invert_count;
            k = (current_string_length - k + 1);
        }
    }

    if (invert_count & 0x1) {
        return '1';
    }

    return '0';
}
