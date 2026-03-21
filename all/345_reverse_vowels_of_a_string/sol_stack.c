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

    char *vowel_characters_stack_array_ptr = (
        (char*)malloc(sizeof(*vowel_characters_stack_array_ptr) * s_length)
    );
    int stack_next_available_index = 0;

    if (NULL == vowel_characters_stack_array_ptr) {
        return s;
    }

    for (int i = 0; '\0' != (s[i]); ++i) {
        if (!isVowels(s[i])) {
            continue;
        }

        vowel_characters_stack_array_ptr[stack_next_available_index] = (s[i]);
        ++stack_next_available_index;
    }

    for (int i = 0; '\0' != (s[i]); ++i) {
        if (!isVowels(s[i])) {
            continue;
        }

        s[i] = (vowel_characters_stack_array_ptr[--stack_next_available_index]);
    }

    free(vowel_characters_stack_array_ptr);
    vowel_characters_stack_array_ptr = NULL;

    return s;
}
