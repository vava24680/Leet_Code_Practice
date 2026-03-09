char* longestCommonPrefix(char** strs, int strsSize) {
    unsigned int common_prefix_length = 0;
    bool continue_loop = true;
    char* common_prefix_string_ptr = NULL;

    while (continue_loop) {
        for (int i = 0; i < strsSize; ++i) {
            if (
                ('\0' == strs[i][common_prefix_length])
                ||
                (strs[i][common_prefix_length] != strs[0][common_prefix_length])
            ) {
                /*
                 * If there is end of string or different character is encountered,
                 * we need to stop iteration and it means this is the end of
                 * longest common prefix.
                 */
                continue_loop = false;

                break;
            }
        }

        if (continue_loop) {
            ++common_prefix_length;
        }
    }

    common_prefix_string_ptr = (
        (char*)malloc(sizeof(char) * (common_prefix_length + 1))
    );
    common_prefix_string_ptr[common_prefix_length] = '\0';

    strncpy(common_prefix_string_ptr, strs[0], common_prefix_length);

    return common_prefix_string_ptr;
}
