#include <stdbool.h>

#define LOWERCASE_LETTERS_COUNT (26)
#define LOWERCASE_CHARACTER_TO_INDEX(c) ((((c) >= ('a')) && ((c) <= ('z'))) ? ((c) - ('a')) : -1)

bool checkStrings(char* s1, char* s2) {
    /*
     * The characters count difference array at index 0 is for the characters
     * positioned at the even index.
     * The characters count difference array at index 1 is for the characters
     * positioned at the odd index.
     */
    int characters_count_difference_array[2][LOWERCASE_LETTERS_COUNT] = {
        {0},
        {0},
    };

    for (int i = 0; '\0' != (s1[i]); ++i) {
        ++(
            characters_count_difference_array[
                    i & 0x1
            ][
                LOWERCASE_CHARACTER_TO_INDEX(s1[i])
            ]
        );
    }

    for (int i = 0; '\0' != (s2[i]); ++i) {
        if (
            0
            ==
            (
                characters_count_difference_array[
                    i & 0x1
                ][
                    LOWERCASE_CHARACTER_TO_INDEX(s2[i])
                ]
            )
        ) {
            /*
             * Return false if the count difference of a character is already 0,
             * it means that character at the even positions or odd positions
             * shows more times than in the string s1.
             */
            return false;
        }

        --(
            characters_count_difference_array[
                i & 0x1
            ][
                LOWERCASE_CHARACTER_TO_INDEX(s2[i])
            ]
        );
    }

    /*
     * If programe is here, it means that the characters at the even positions
     * (odd positions) in the string s1 has the same count as the characters
     * at the even positions (odd positions) in the string s2.
     */

    return true;
}
