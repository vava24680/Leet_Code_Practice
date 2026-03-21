#include <string.h>

bool isVowels(const char c) {
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;

            break;
        default:
            break;
    }

    return false;
}

void swapTwoCharacters(char * const c1, char * const c2) {
    if (c1 == c2) {
        return;
    }

    char temp_c;

    temp_c = (*c1);
    (*c1) = (*c2);
    (*c2) = temp_c;
}

char* reverseVowels(char* s) {
    const int s_length = ((int)strlen(s));
    int left_index = 0;
    int right_index = (s_length - 1);

    while (1) {
        while ((left_index < right_index) && (!isVowels(s[left_index]))) {
            /* Find the next vowel character from left. */
            ++left_index;
        }

        while ((right_index > left_index) && (!isVowels(s[right_index]))) {
            /* Find the next vowel character from right. */
            --right_index;
        }

        if (left_index >= right_index) {
            /*
             * Break if the left index is equal or greater than the right index.
             * When this happens, it means all vowel characters have been
             * reversed.
             */
            break;
        }

        /*
         * Swap the vowels characters indexed by the left index and the right
         * index.
         */
        swapTwoCharacters(&(s[left_index]) , &(s[right_index]));

        /* Update the left index and the right index. */
        ++left_index;
        --right_index;
    }

    return s;
}
