#include <stdlib.h>

typedef struct {
    unsigned int characters_bitmap;
    int word_length;
} WordInfoST;

static inline int max(const int i1, const int i2) {
    return ((i1 > i2) ? i1 : i2);
}

int maxProduct(char** words, int wordsSize) {
    int maximum_length = 0;
    WordInfoST *word_info_st_array_ptr = (WordInfoST*)malloc(
        sizeof(*word_info_st_array_ptr) * wordsSize
    );

    if (NULL == word_info_st_array_ptr) {
        return 0;
    }

    for (int i = 0; i < wordsSize; ++i) {
        unsigned int current_word_characters_bitmap = 0U;
        int current_word_length = 0;

        /* Compute current word's characters' bitmap. */
        for (; '\0' != words[i][current_word_length]; ++current_word_length) {
            current_word_characters_bitmap |= (
                1U
                <<
                ((unsigned int)(words[i][current_word_length] - 'a'))
            );
        }

        /* Try current word with every word before it. */
        for (int j = 0; j < i; ++j) {
            if (
                current_word_characters_bitmap
                &
                (word_info_st_array_ptr[j].characters_bitmap)
            ) {
                /*
                 * Continue to next word if current two words has common
                 * characters.
                 */
                continue;
            }

            /* Update maximum length if needed. */
            maximum_length = max(
                maximum_length,
                current_word_length * word_info_st_array_ptr[j].word_length
            );
        }

        word_info_st_array_ptr[i].characters_bitmap = (
            current_word_characters_bitmap
        );
        word_info_st_array_ptr[i].word_length = current_word_length;
    }

    free(word_info_st_array_ptr);
    word_info_st_array_ptr = NULL;

    return maximum_length;
}
