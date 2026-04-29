#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#define LOWERCASE_LETTERS_COUNT (26)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct AnswerArrayStruct {
    char **array_ptr;
    int array_length;
    int next_available_index;
} AnswerArrayST;

static inline int min(const int i1, const int i2) {
    return ((i1 < i2) ? i1 : i2);
}

static bool addWordPointerToAnswerArrayST(
    char *word_ptr,
    AnswerArrayST * answer_array_st_ptr
) {
    char **tmp_ptr = NULL;
    int new_array_length = 0;

    if (
        (answer_array_st_ptr->next_available_index)
        >=
        (answer_array_st_ptr->array_length)
    ) {
        if (0 == (answer_array_st_ptr->array_length)) {
            new_array_length = 4;
        }
        else {
            new_array_length = ((answer_array_st_ptr->array_length) << 1);
        }

        tmp_ptr = realloc(
            (void*)(answer_array_st_ptr->array_ptr),
            (
                sizeof(*(answer_array_st_ptr->array_ptr))
                *
                new_array_length
            )
        );

        if (NULL == tmp_ptr) {
            return false;
        }

        answer_array_st_ptr->array_length = new_array_length;
        answer_array_st_ptr->array_ptr = tmp_ptr;
    }

    (answer_array_st_ptr->array_ptr)[
        (answer_array_st_ptr->next_available_index)++
    ] = word_ptr;

    return true;
}

char** commonChars(char** words, int wordsSize, int* returnSize) {
    AnswerArrayST answer_array_st = {
        .array_ptr = NULL,
        .array_length = 0,
        .next_available_index = 0,
    };
    int minimum_count = 0;
    int *data_blocks_array_ptr = (
        (int*)calloc(
            wordsSize * LOWERCASE_LETTERS_COUNT,
            sizeof(*data_blocks_array_ptr)
        )
    );
    int **counters_array_ptr = (
        (int**)malloc(sizeof(*counters_array_ptr) * wordsSize)
    );
    char *word_ptr = NULL;

    for (int i = 0; i < wordsSize; ++i) {
        /* Compute each character's count in each given word. */
        counters_array_ptr[i] = (
            data_blocks_array_ptr + (i * LOWERCASE_LETTERS_COUNT)
        );

        word_ptr = words[i];

        for (int j = 0; '\0' != (words[i][j]); ++j) {
            ++(counters_array_ptr[i][(words[i][j]) - 'a']);
        }
    }

    for (int i = 0; i < LOWERCASE_LETTERS_COUNT; ++i) {
        /* Find each letter's minimum count. */
        minimum_count = INT_MAX;

        for (int j = 0; j < wordsSize; ++j) {
            minimum_count = min(minimum_count, counters_array_ptr[j][i]);
        }

        if (INT_MAX == minimum_count) {
            /*
             * If a letter's minimum count is INT_MAX, which means that this
             * letter does not show in the given words at all.
             */
            continue;
        }

        for (int j = 0; j < minimum_count; ++j) {
            /* Generate result word string to be added to answer array. */
            word_ptr = (char*)malloc(sizeof(*word_ptr) * 2);
            word_ptr[0] = (char)(((int)'a') + i);
            word_ptr[1] = '\0';

            /* Add a word to answer array. */
            addWordPointerToAnswerArrayST(
                word_ptr,
                &answer_array_st
            );
        }
    }

    free(data_blocks_array_ptr);
    data_blocks_array_ptr = NULL;

    free(counters_array_ptr);
    counters_array_ptr = NULL;

    (*returnSize) = (answer_array_st.next_available_index);

    return (answer_array_st.array_ptr);
}
