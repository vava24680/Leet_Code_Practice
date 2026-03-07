INT32_MAX = ((1 << 31) - 1)
INT32_MIN = -(1 << 31)


def does_mul_overflow_or_underflow(multiplicand: int, multiplier: int) -> bool:
    if (
        (1 == multiplicand)
        or
        (0 == multiplicand)
        or
        (1 == multiplier)
        or
        (0 == multiplier)
    ):
        return False
    elif -1 == multiplicand:
        return (INT32_MIN == multiplier)
    elif -1 == multiplier:
        return (INT32_MIN == multiplicand)
    elif multiplier > 0:
        if multiplicand > 0:
            return multiplicand > (INT32_MAX // multiplier)
        else:
            return multiplicand < (INT32_MIN // multiplier)
    elif multiplicand > 0:
        # Positive * negative
        return multiplicand > (INT32_MIN // multiplier)

    # Negative * negative
    return multiplicand < (INT32_MAX // multiplier)

def does_add_overflow_or_underflow(i1: int, i2: int) -> bool:
    if i2 > 0:
        return i1 > (INT32_MAX - i2)

    return i1 < (INT32_MIN - i2)

class Solution:
    def reverse(self, x: int) -> int:
        answer = 0
        remainder = 0
        is_negative_number = (x < 0)

        while (x):
            x, remainder = divmod(x, 10)

            if is_negative_number and remainder:
                # Python remainder always has same sign bit as the divisor.
                # So we need to convert remainder to negative value if it is
                # not 0 and the given number is a negative number.
                # Just decrease it by the amount of the divisor value,
                # which is 10.
                remainder -= 10

            if does_mul_overflow_or_underflow(answer, 10):
                return 0

            answer *= 10

            if does_add_overflow_or_underflow(answer, remainder):
                return 0

            answer += remainder

            # Python integer divison is always rounded down, so we need
            # add 1 back if the given number is a negative number and remainder
            # is not 0.
            if is_negative_number and remainder:
                x += 1

        return answer


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [123],
        [-123],
        [120],
        [123456789],
        [1234567899],
        [-10],
        [-900000],
    ]

    for testcase in testcases_list:
        print(sol.reverse(*testcase))
