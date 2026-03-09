#include <stdbool.h>
#include <stdlib.h>

char* findDifferentBinaryString(char** nums, int numsSize) {
    char* answer_string_ptr = (char*)malloc(
        sizeof(*answer_string_ptr) * (numsSize + 1)
    );

    for (int i = 0; i < numsSize; ++i) {
        /*
         * Make answer_string_ptr[i] is the complement value of nums[i][i].
         * This operation can make the answer string does not show in the
         * given nums array.
         */
        answer_string_ptr[i] = ((((nums[i][i]) - '0') ^ 1) + '0');
    }

    answer_string_ptr[numsSize] = '\0';

    return answer_string_ptr;
}
