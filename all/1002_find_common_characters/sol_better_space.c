#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define LOWERCASE_LETTERS_COUNT (26)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static inline int min(const int i1, const int i2) {
    return ((i1 < i2) ? i1 : i2);
}

static void computeLettersCount(
    const char *word_ptr,
    int * letters_count_array_ptr
) {
    for (int i = 0; '\0' != (word_ptr[i]); ++i) {
        ++(letters_count_array_ptr[(word_ptr[i]) - 'a']);
    }
}

char** commonChars(char** words, int wordsSize, int* returnSize) {
    char** answer_array_ptr = NULL;
    int answer_array_length = 0;
    int letters_minimum_counter_array[LOWERCASE_LETTERS_COUNT] = {0};
    int letters_counter_array[LOWERCASE_LETTERS_COUNT] = {0};

    /*
     * Compute each letter's count in the first given word and store result
     * in the letters minimum count array.
     */
    computeLettersCount(words[0], &(letters_minimum_counter_array[0]));

    for (int i = 1; i < wordsSize; ++i) {
        /* Reset letters counter. */
        memset(
            &(letters_counter_array[0]),
            0,
            sizeof(letters_counter_array[0]) * LOWERCASE_LETTERS_COUNT
        );

        /*
         * Compute each letter's count in the iterated word and store result
         * in the letters count array.
         */
        computeLettersCount(words[i], &(letters_counter_array[0]));

        /* Update each letter's minimum count. */
        for (int j = 0; j < LOWERCASE_LETTERS_COUNT; ++j) {
            letters_minimum_counter_array[j] = min(
                letters_minimum_counter_array[j],
                letters_counter_array[j]
            );
        }
    }

    /* Compute answer array size. */
    for (int i = 0; i < LOWERCASE_LETTERS_COUNT; ++i) {
        answer_array_length += (letters_minimum_counter_array[i]);
    }

    /* Allocate memory for answer array. */
    answer_array_ptr = (
        (char**)malloc(sizeof(*answer_array_ptr) * answer_array_length)
    );

    /* Populate answer array. */
    for (
        int i = 0, next_available_index = 0;
        i < LOWERCASE_LETTERS_COUNT;
        ++i
    ) {
        if (letters_minimum_counter_array[i]) {
            char letter = ((int)'a') + i;

            for (int j = 0; j < (letters_minimum_counter_array[i]); ++j) {
                char *word_ptr = (char*)malloc(sizeof(*word_ptr) * 2);
                word_ptr[0] = letter;
                word_ptr[1] = '\0';

                answer_array_ptr[next_available_index++] = word_ptr;
            }
        }
    }

    (*returnSize) = answer_array_length;

    return answer_array_ptr;
}
