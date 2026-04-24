#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** twoEditWords(
    char** queries,
    int queriesSize,
    char** dictionary,
    int dictionarySize,
    int* returnSize
) {
    char **answer_strings_array_ptr = (
        (char**)malloc(sizeof(*answer_strings_array_ptr) * queriesSize)
    );
    int edits_count = 0;

    (*returnSize) = 0;

    for (int i = 0; i < queriesSize; ++i) {
        /*
         * Try every word in the queries list with every word in the target
         * list to check if current query word can be converted to one of
         * word in the target list by changing at most two characters.
         */
        for (int j = 0; j < dictionarySize; ++j) {
            edits_count = 0;

            for (
                int qsi = 0, tsi = 0;
                ('\0' != (queries[i][qsi])) && ('\0' != (dictionary[j][tsi]));
                ++qsi, ++tsi
            ) {
                /*
                 * Iterate queries[i] and dictionary[j] to check if we can
                 * convert queries[i] to dictionary[j] by changing at most
                 * two characters in queries[i].
                 */
                if ((queries[i][qsi]) != (dictionary[j][tsi])) {
                    ++edits_count;
                }

                if (edits_count > 2) {
                    /*
                     * Break checking process if count of the characters to be
                     * changed is greater than 2.
                     */
                    break;
                }
            }

            if (edits_count <= 2) {
                /*
                 * Current query word can be converted to one of word in the
                 * target list by changing at most two characters.
                 */

                /* Add current word to answer list. */
                answer_strings_array_ptr[*returnSize] = (queries[i]);
                ++(*returnSize);

                /*
                 * Break inner loop since we already find a proper target word
                 * for current query word.
                 */
                break;
            }
        }
    }

    return answer_strings_array_ptr;
}
