#include <stdbool.h>

bool checkOnesSegment(char* s) {
    /*
     * As the starting character of s is 1, we just need to check if there has
     * '01' in s that will start second continuous segment of ones.
     */
    for (int i = 1; '\0' != s[i]; ++i) {
        if (('0' == s[i - 1]) && ('1' == s[i])) {
            return false;
        }
    }

    return true;
}
