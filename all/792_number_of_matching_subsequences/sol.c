#include <stddef.h>
#include <stdlib.h>

#define LOWERCASE_LETTERS_COUNT (26)
#define LOWERCASE_CHARACTER_TO_INDEX(c) ((c) - ('a'))

typedef struct MatchingStringNode {
    const char * comparing_char_ptr;
    struct MatchingStringNode *next_node_ptr;
} MatchingStringNodeST;

int numMatchingSubseq(char* s, char** words, int wordsSize) {
    int subsequences_count = 0;
    MatchingStringNodeST *matching_string_nodes_array_ptr = (
        (MatchingStringNodeST*)malloc(
            sizeof(*matching_string_nodes_array_ptr) * wordsSize
        )
    );
    MatchingStringNodeST *next_node_ptr = NULL;

    /*
     * Use linked list to store a chain of strings that are currently can be
     * matched with a certain lowercase character.
     */
    MatchingStringNodeST* matching_strings_linked_lists_array[
        LOWERCASE_LETTERS_COUNT
    ] = {0};

    for (int i = 0; i < wordsSize; ++i) {
        matching_string_nodes_array_ptr[i].comparing_char_ptr = words[i];
        matching_string_nodes_array_ptr[i].next_node_ptr = (
            matching_strings_linked_lists_array[
                LOWERCASE_CHARACTER_TO_INDEX(words[i][0])
            ]
        );
        matching_strings_linked_lists_array[
            LOWERCASE_CHARACTER_TO_INDEX(words[i][0])
        ] = &(matching_string_nodes_array_ptr[i]);
    }

    for (int i = 0; '\0' != s[i]; ++i) {
        /* Copy corresponding linked list head node pointer. */
        MatchingStringNodeST *current_matching_string_node_ptr = (
            matching_strings_linked_lists_array[
                LOWERCASE_CHARACTER_TO_INDEX(s[i])
            ]
        );

        /*
         * Make the corresponding linked list to empty since if new node has to
         * be inserted to it, it can treated as a brand new linked list without
         * any node and we won't be confused with the odd nodes and new nodes.
         */
        matching_strings_linked_lists_array[
            LOWERCASE_CHARACTER_TO_INDEX(s[i])
        ] = NULL;

        while (NULL != current_matching_string_node_ptr) {
            /* Backup next node pointer. */
            next_node_ptr = (current_matching_string_node_ptr->next_node_ptr);

            /*
             * Move the pointer stored in the linked list node one step
             * forward.
             */
            ++(current_matching_string_node_ptr->comparing_char_ptr);

            if (
                '\0'
                ==
                (*(current_matching_string_node_ptr->comparing_char_ptr))
            ) {
                /*
                 * Increase the subsequences counter by 1 if current string is
                 * iterated to the end.
                 */
                ++subsequences_count;
            }
            else {
                /* Add current node to the corresponding linked list. */
                current_matching_string_node_ptr->next_node_ptr = (
                    matching_strings_linked_lists_array[
                        LOWERCASE_CHARACTER_TO_INDEX(
                            *(current_matching_string_node_ptr->comparing_char_ptr)
                        )
                    ]
                );
                matching_strings_linked_lists_array[
                    LOWERCASE_CHARACTER_TO_INDEX(
                        *(current_matching_string_node_ptr->comparing_char_ptr)
                    )
                ] = current_matching_string_node_ptr;
            }

            /* Continue to next node in the current linked list. */
            current_matching_string_node_ptr = next_node_ptr;
        }
    }

    free(matching_string_nodes_array_ptr);
    matching_string_nodes_array_ptr = NULL;

    return subsequences_count;
}
