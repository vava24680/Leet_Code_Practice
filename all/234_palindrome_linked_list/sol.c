#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    int *values_array_ptr = NULL;
    int values_count = 0;
    struct ListNode *current_node_ptr = head;

    while (NULL != current_node_ptr) {
        ++values_count;
        current_node_ptr = (current_node_ptr->next);
    }

    values_array_ptr = (int*)malloc(sizeof(int) * values_count);

    current_node_ptr = head;
    values_count = 0;

    while (NULL != current_node_ptr) {
        values_array_ptr[values_count++] = (current_node_ptr->val);
        current_node_ptr = (current_node_ptr->next);
    }

    for (int i = 0; i < (values_count >> 1); ++i) {
        if (
            (values_array_ptr[i])
            !=
            (values_array_ptr[values_count - 1 - i])
        ) {
            return false;
        }
    }

    free(values_array_ptr);
    values_array_ptr = NULL;

    return true;
}
