int minPartitions(char* n) {
    char maximum_digit = '0';

    while ('\0' != (*n)) {
        if ((*n) > maximum_digit) {
            maximum_digit = (*n);
        }

        ++n;
    }

    return maximum_digit - '0';
}
