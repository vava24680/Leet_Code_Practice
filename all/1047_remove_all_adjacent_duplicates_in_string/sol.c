char* removeDuplicates(char* s) {
    /* Use the given string as stack. */
    int stack_next_available_index = 0;

    for (int i = 0; '\0' != s[i]; ++i) {
        if (
            (0 == stack_next_available_index)
            ||
            (s[stack_next_available_index - 1] != s[i])
        ) {
            /*
             * Push current iterated character to stack if stack is currently
             * empty or current iterated character is different from the
             * character at the stack top.
             */
            s[stack_next_available_index] = s[i];
            ++stack_next_available_index;
        }
        else {
            /*
             * Pop the top character from the stack if current iterated
             * character is as same as it.
             */
            --stack_next_available_index;
        }
    }

    /* Add null-terminated character. */
    s[stack_next_available_index] = '\0';

    return s;
}
