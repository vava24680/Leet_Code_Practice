#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
    /*
     * Use two pointers to solve this problem.
     * The first pointer points to the start of the string "s".
     * The second pointer points to the start of the string "t".
     *
     * 1. Check if the first pointer or the second pointer points to the null
     *    terminator ('\0'), if yes, go to step 3. Otherwise, go to next step.
     * 2. Check if if the current characters pointed by the two pointers are
     *    the same, if yes, advance both pointer one step ahead.
     *    Otherwise, advance the second pointer one step ahead only.
     * 3. Check if the first pointer points to the null terminator ('\0'),
     *    if yes, return true. Otherwise, return false.
     */
    char *s_ptr = s, *t_ptr = t;

    while (('\0' != (*s_ptr)) && ('\0' != (*t_ptr))) {
        if ((*s_ptr) == (*t_ptr)) {
            s_ptr++;
            t_ptr++;
        }
        else {
            t_ptr++;
        }
    }

    return ('\0' == (*s_ptr));
}
