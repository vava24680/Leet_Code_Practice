bool hasAlternatingBits(int n) {
    int previous_bit = n & 1;
    int process_number = n >> 1;

    while (0 != process_number) {
        if (previous_bit == (process_number & 1)) {
            return false;
        }

        previous_bit = process_number & 1;
        process_number = process_number >> 1;
    }

    return true;
}
