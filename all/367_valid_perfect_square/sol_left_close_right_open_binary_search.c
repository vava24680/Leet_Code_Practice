bool isPerfectSquare(int num) {
    /*
     * In the range of 1 to num, find the minimum k such that:
     * 1. 1 <= k <= num.
     * 2. k * k >= num.
     *
     * After k is found, check if k * k equals to num.
     */

    long long left_value = 1LL, right_value = ((long long)num);
    long long middle_value = 0LL;

    while (left_value < right_value) {
        middle_value = left_value + ((right_value - left_value) >> 1);

        if (((long long)num) > (middle_value * middle_value)) {
            left_value = (middle_value + 1LL);
        }
        else {
            right_value = middle_value;
        }
    }

    return (((long long)num) == (left_value * left_value));
}
