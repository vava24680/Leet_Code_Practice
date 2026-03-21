#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isVowel(const char c) {
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

int compareFunction(const void *p1, const void *p2) {
    const char c1 = (*((const char*)p1));
    const char c2 = (*((const char*)p2));

    return (((int)c1) > ((int)c2)) - (((int)c1) < ((int)c2));
}

char* sortVowels(char* s) {
    const int s_length = ((int)strlen(s));

    int vowel_characters_count = 0;
    char *vowel_characters_array_ptr = (
        (char*)malloc(sizeof(*vowel_characters_array_ptr) * s_length)
    );

    for (int i = 0; i < s_length; ++i) {
        if (!isVowel(s[i])) {
            continue;
        }

        vowel_characters_array_ptr[vowel_characters_count++] = (s[i]);
    }

    /* Sort all the vowel characters in non-decreasing order. */
    qsort(
        vowel_characters_array_ptr,
        vowel_characters_count,
        sizeof(*vowel_characters_array_ptr),
        &compareFunction
    );

    for (
        int i = 0, j = 0;
        (i < s_length) && (j < vowel_characters_count);
        ++i
    ) {
        if (!isVowel(s[i])) {
            continue;
        }

        s[i] = (vowel_characters_array_ptr[j]);

        ++j;
    }

    free(vowel_characters_array_ptr);
    vowel_characters_array_ptr = NULL;

    return s;
}
