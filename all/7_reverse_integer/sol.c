#include <stdbool.h>
#include <stdint.h>

bool does_mul_overflow_or_underflow(
    const int multiplicand,
    const int multiplier
) {
    if (
        (1 == multiplicand)
        ||
        (0 == multiplicand)
        ||
        (1 == multiplier)
        ||
        (0 == multiplier)
    ) {
        return false;
    }
    else if (-1 == multiplicand) {
        return (INT32_MIN == multiplier);
    }
    else if (-1 == multiplier) {
        return (INT32_MIN == multiplicand);
    }
    else if (multiplier > 0) {
        if (multiplicand > 0) {
            /* Positive * positive. */
            return (multiplicand > (INT32_MAX / multiplier));
        }
        else {
            /* Negative * positive. */
            return (multiplicand < (INT32_MIN / multiplier));
        }
    }
    else if (multiplicand > 0) {
        /* Positive * negative */
        return (multiplicand > (INT32_MIN / multiplier));
    }

    /* Negative * negative */
    return (multiplicand < (INT32_MAX / multiplier));
}

bool does_add_overflow_or_underflow(const int i1, const int i2) {
    if (i2 > 0) {
        return (i1 > (INT32_MAX - i2));
    }

    return (i1 < (INT32_MIN - i2));
}

int reverse(int x) {
    int answer = 0;
    int remainder = 0;

    while (x) {
        /*
         * In C, remainder always has same sign bit as the dividend, which is
         * what we need in this problem.
         */
        remainder = x % 10;

        if (does_mul_overflow_or_underflow(answer, 10)) {
            return 0;
        }

        answer *= 10;

        if (does_add_overflow_or_underflow(answer, remainder)) {
            return 0;
        }

        answer += remainder;

        /*
         * In C, integer divison is always rounded to zero, which is what we
         * need in this problem.
         */
        x /= 10;
    }

    return answer;
}
