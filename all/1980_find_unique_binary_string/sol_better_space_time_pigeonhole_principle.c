#include <stdbool.h>
#include <stdlib.h>

char* findDifferentBinaryString(char** nums, int numsSize) {
    bool* numbers_shown_hash_map_array_ptr = (
        (bool*)calloc(numsSize + 1, sizeof(*numbers_shown_hash_map_array_ptr))
    );
    char* answer_string_ptr = (char*)malloc(
        sizeof(*answer_string_ptr) * (numsSize + 1)
    );
    int minimum_not_shown_number = 0;
    int current_number = 0;

    for (int i = 0; i < numsSize; ++i) {
        current_number = 0;

        for (int j = 0; '\0' != nums[i][j]; ++j) {
            current_number = ((current_number << 1) + (nums[i][j] - '0'));
        }

        if (current_number > numsSize) {
            continue;
        }

        numbers_shown_hash_map_array_ptr[current_number] = true;
    }

    for (
        minimum_not_shown_number = 0;
        minimum_not_shown_number < (numsSize + 1);
        ++minimum_not_shown_number
    ) {
        if (!numbers_shown_hash_map_array_ptr[minimum_not_shown_number]) {
            break;
        }
    }

    for (int i = 0; i < numsSize; ++i) {
        answer_string_ptr[numsSize - (i + 1)] = (
            (minimum_not_shown_number & 0x1) + '0'
        );
        minimum_not_shown_number >>= 1;
    }

    free(numbers_shown_hash_map_array_ptr);
    numbers_shown_hash_map_array_ptr = NULL;

    answer_string_ptr[numsSize] = '\0';

    return answer_string_ptr;
}
