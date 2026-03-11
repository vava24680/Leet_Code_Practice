void swapTwoCharacters(char * const c1, char * const c2) {
    char temp_c = *c1;
    (*c1) = (*c2);
    (*c2) = temp_c;
}

void reverseString(char* s, int sSize) {
    for (int i = 0; i < (sSize >> 1); ++i) {
        swapTwoCharacters(&(s[i]), &(s[sSize - 1 - i]));
    }

    return;
}
