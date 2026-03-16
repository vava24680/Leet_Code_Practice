#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

size_t computeGCD(size_t a, size_t b) {
    size_t tmp = 0;

    while (b) {
        tmp = a;
        a = b;
        b = tmp % b;
    }

    return a;
}

bool isStringDivisible(
    const char *str_ptr,
    const char *divisor_string_ptr
) {
    const char *divisor_string_ptr_bk = divisor_string_ptr;

    while ('\0' != (*str_ptr)) {
        if ('\0' == (*divisor_string_ptr)) {
            /*
             * The given divisor string is iterated to the end, make pointer
             * goes back to the start.
             */
            divisor_string_ptr = divisor_string_ptr_bk;
        }

        if ((*str_ptr) != (*divisor_string_ptr)) {
            return false;
        }

        ++str_ptr;
        ++divisor_string_ptr;
    }

    /*
     * If the given string is iterated to the end, the given string is divisible
     * by the given divisor string if the given divisor string is iterated to
     * the end too.
     */
    return '\0' == (*divisor_string_ptr);
}

char* gcdOfStrings(char* str1, char* str2) {
    /*
     * Compute the GCD of the lengths of the str1 and str2, and use that value
     * to extract a divisor substring from the start of str1 or str1 and the
     * length should be that GCD value.
     *
     * Check if both strings can be divisible by the divisor string.
     */
    size_t gcd_of_both_strings_lengths = computeGCD(
        strlen(str1),
        strlen(str2)
    );
    char *possible_maximum_common_divisor_string = (char*)malloc(
        sizeof(char) * (gcd_of_both_strings_lengths + 1)
    );

    /* Construct possible common divisor string. */
    possible_maximum_common_divisor_string[gcd_of_both_strings_lengths] = '\0';
    strncpy(
        possible_maximum_common_divisor_string,
        str1,
        gcd_of_both_strings_lengths
    );

    if (
        (!isStringDivisible(str1, possible_maximum_common_divisor_string))
        ||
        (!isStringDivisible(str2, possible_maximum_common_divisor_string))
    ) {
        possible_maximum_common_divisor_string[0] = '\0';
    }

    return possible_maximum_common_divisor_string;
}
