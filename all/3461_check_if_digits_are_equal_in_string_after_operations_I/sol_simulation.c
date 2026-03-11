#include <stdbool.h>

static inline char convertDigitToChar(const int digit) {
    if ((digit < 0) || (digit > 9)) {
        return ' ';
    }

    return '0' + digit;
}

static inline int convertCharToDigit(const char c) {
    if ((c > '9') || (c < '0')) {
        return -1;
    }

    return c - '0';
}

bool hasSameDigits(char* s) {
    int current_valid_digits_count = 0;
    int index = 0;

    do {
        index = 0;
        current_valid_digits_count = 0;

        while (('\0' != s[index]) && ('\0' != s[index + 1])) {
            /*
             * Iterate each character until the last one character
             * (not included).
             */
            s[index] = convertDigitToChar(
                (convertCharToDigit(s[index]) + convertCharToDigit(s[index + 1]))
                %
                10
            );

            /* Count valid digits count after performing required operations. */
            ++current_valid_digits_count;
            ++index;
        }

        /*
         * Change origin last character to null-terminated character
         * as we do not need it anymore.
         */
        s[index] = '\0';

        /* Terminate loop if there are only two or less digits. */
    } while (current_valid_digits_count > 2);

    return s[0] == s[1];
}
