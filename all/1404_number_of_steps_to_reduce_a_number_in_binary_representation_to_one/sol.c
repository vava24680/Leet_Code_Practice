#include <string.h>

int numSteps(char* s) {
    int s_length = strlen(s);
    int steps_count = 0;
    int carry_value = 0;

    if (s_length <= 1) {
        return 0;
    }

    for (int i = s_length - 1; i > 0; --i) {
        /*
         * Compute current LSB actual value by adding its original value with
         * carry value.
         */
        if (1 == (carry_value + (s[i] - '0'))) {
            steps_count += 2;
            carry_value = 1;
        }
        else {
            steps_count += 1;

            if (carry_value && (s[i] - '0')) {
                carry_value = 1;
            }
            else {
                carry_value = 0;
            }
        }
    }

    /*
     * MSB must be 1, and if carry value is still 1, we need to do one more
     * operation to make 1 to 1.
     */
    return steps_count + carry_value;
}
