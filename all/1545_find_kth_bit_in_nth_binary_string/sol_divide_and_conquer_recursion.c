char findKthBit(int n, int k) {
    if (1 == n) {
        /* Recursion base case. */
        return '0';
    }

    const int current_string_length = ((1 << n) - 1);

    if ((k - 1) == (current_string_length >> 1)) {
        return '1';
    }
    else if ((k - 1) < (current_string_length >> 1)) {
        return findKthBit(n - 1, k);
    }

    return '1' - findKthBit(n - 1, current_string_length - k + 1) + '0';
}
