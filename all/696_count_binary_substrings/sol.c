#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct GroupInfoStruct {
    int characters_count;
    char binary_value_character;
} GroupInfoST;

bool copyGroupInfoST(
    GroupInfoST * const new_group_info_st_ptr,
    const GroupInfoST * const original_group_info_st_ptr
) {
    if (
        (NULL == new_group_info_st_ptr)
        ||
        (NULL == original_group_info_st_ptr)
    ) {
        return false;
    }

#if 1
    memcpy(
        (void*)new_group_info_st_ptr,
        (void*)original_group_info_st_ptr,
        sizeof(*original_group_info_st_ptr)
    );
#else
    (new_group_info_st_ptr->characters_count) = \
        (original_group_info_st_ptr->characters_count);
    (new_group_info_st_ptr->binary_value_character) = (original_group_info_st_ptr->binary_value_character);
#endif

    return true;
}

bool isANewValidSubstringFoundInCurrentTwoGroups(
    const GroupInfoST * const current_group_info_st_ptr,
    const GroupInfoST * const previous_group_info_st_ptr
) {
    /*
     * If the binary value characters count recorded in the previous group is greater
     * than or equal to the binary characters count recorded in the current group,
     * it means there is a new substring can be formed.
     */
    if (
        (NULL == previous_group_info_st_ptr)
        ||
        (NULL == current_group_info_st_ptr)
    ) {
        return false;
    }

    if (
        (previous_group_info_st_ptr->characters_count)
        >=
        (current_group_info_st_ptr->characters_count)
    ) {
        return true;
    }

    return false;
}

int countBinarySubstrings(char* s) {
    /*
     * Use two groups of start index and binary value characters count track current
     * adjacent two groups of consecutive 1s and consecutive 0s, and update
     * number of valid substrings dynamically.
     */
    int substrings_count = 0;
    char *binary_string_ptr = s;
    GroupInfoST previous_group_info_st = {
        .characters_count = 0,
        .binary_value_character = -1,
    };
    GroupInfoST current_group_info_st = {
        .characters_count = 0,
        .binary_value_character = -1,
    };

    if ('\0' == (*s)) {
        return 0;
    }

    current_group_info_st.characters_count = 1;
    current_group_info_st.binary_value_character = *binary_string_ptr;
    binary_string_ptr += 1;

    while ('\0' != (*binary_string_ptr)) {
        if (
            current_group_info_st.binary_value_character
            !=
            *binary_string_ptr
        ) {
            /*
             * If current binary value characters is different than the one
             * recorded in the current group, it menas there is bit value
             * character change (1->0 or 0->1) starting from current index,
             * we need to preserve the original current group information
             * to another group and update current group information.
             */

            /*
             * Copy current group info struct to another group info struct that
             * is used to preserve original current group information.
             */
            copyGroupInfoST(&previous_group_info_st, &current_group_info_st);

            /* Update current group information. */
            current_group_info_st.characters_count = 1;
            current_group_info_st.binary_value_character = *binary_string_ptr;
        }
        else {
            /*
             * If current binary value character is as same as the recorded value
             * in the current group, just increase binary value character count
             * recorded in the current group by 1.
             */
            (current_group_info_st.characters_count) += 1;
        }

        if (
            true
            ==
            isANewValidSubstringFoundInCurrentTwoGroups(
                &current_group_info_st,
                &previous_group_info_st
            )
        ) {
            /*
             * Increase substrings count by 1 if there is a new valid
             * substring found in current two groups.
             */
            substrings_count += 1;
        }

        binary_string_ptr += 1;
    }

    return substrings_count;
}
