#include <stdbool.h>

#define VOWEL_CHARACTERS_COUNT (10)

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

int vowelsToIndexMapping(const char vowel) {
    switch (vowel) {
        case 'A':
            return 0;
        case 'E':
            return 1;
        case 'I':
            return 2;
        case 'O':
            return 3;
        case 'U':
            return 4;
        case 'a':
            return 5;
        case 'e':
            return 6;
        case 'i':
            return 7;
        case 'o':
            return 8;
        case 'u':
            return 9;
        default:
            break;
    }

    return -1;
}

char* sortVowels(char* s) {
    const char* NON_DECREASING_VOWEL_CHARACTERS_STRING = "AEIOUaeiou";
    const char vowels_order_array[] = {
        'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u',
    };
    int vowels_counter[VOWEL_CHARACTERS_COUNT] = {0};
    int next_character_index = 0;

    for (int i = 0; '\0' != (s[i]); ++i) {
        if (!isVowel(s[i])) {
            continue;
        }

        ++vowels_counter[vowelsToIndexMapping(s[i])];
    }

    for (int i = 0, current_vowel_character_index = 0; '\0' != (s[i]); ++i) {
        if (!isVowel(s[i])) {
            continue;
        }

        while (0 == vowels_counter[current_vowel_character_index]) {
            ++current_vowel_character_index;
        }

        s[i] = (
            NON_DECREASING_VOWEL_CHARACTERS_STRING[
                current_vowel_character_index
            ]
        );
        --(vowels_counter[current_vowel_character_index]);
    }

    return s;
}
