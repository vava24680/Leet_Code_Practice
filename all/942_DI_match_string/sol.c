#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* s, int* returnSize) {
    const int s_length = ((int)strlen(s));
    int *result_array = NULL;
    int current_greatest_candidate_number = 0;
    int current_lowest_candidate_number= 0;

    /* Call strlen function once to reduce redudant iterating of the string `s`. */
    current_greatest_candidate_number = s_length;
    result_array = (int*)malloc(sizeof(int) * (s_length + 1));

    if (NULL == result_array) {
        (*returnSize) = 0;

        return NULL;
    }

    for (int i = 0; i < s_length; ++i) {
        if ('D' == s[i]) {
            /*
             * As 'D' means current element must be greater than the next
             * element, but we still don't know next element and its
             * relationship with next two element.
             * To play safe and retain flexibiliy, we use current greatest
             * candidate number as current element.
             */
            result_array[i] = current_greatest_candidate_number;

            /* Update new current greatest candidate number. */
            --current_greatest_candidate_number;
        }
        else if ('I' == s[i]) {
            /*
             * As 'I' means current element must be smaller than the next
             * element, but we still don't know next element and its
             * relationship with next two element.
             * To play safe and retain flexibiliy, we use current lowest
             * candidate number as current element.
             */
            result_array[i] = current_lowest_candidate_number;

            /* Update new current lowest candidate number. */
            ++current_lowest_candidate_number;
        }
    }

    /*
     * After iterating the given string `s`, the current greatest candidate
     * number and the current lowest candidate number should be the same,
     * and that number will be the last number to fill in the result array.
     */
    result_array[s_length] = current_greatest_candidate_number;

    (*returnSize) = (s_length + 1);

    return result_array;
}
