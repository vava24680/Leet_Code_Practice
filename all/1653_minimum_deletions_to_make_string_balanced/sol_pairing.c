int minimumDeletions(char* s) {
    int minimum_deletions_count = 0;
    int current_not_dealt_b_count = 0;

    for (int i = 0; '\0' != s[i]; ++i) {
        if ('b' == s[i]) {
            ++current_not_dealt_b_count;
        }
        else if ('a' == s[i] && current_not_dealt_b_count) {
            --current_not_dealt_b_count;
            ++minimum_deletions_count;
        }
    }

    return minimum_deletions_count;
}
