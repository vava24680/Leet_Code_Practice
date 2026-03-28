#include <stddef.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *previous_node = NULL;
    struct ListNode *current_node = head;
    struct ListNode *next_node_ptr = NULL;

    while (NULL != current_node) {
        /* Save the next node pointer. */
        next_node_ptr = (current_node->next);

        /* Make the next node pointer point to the previous node. */
        (current_node->next) = previous_node;

        /* Change previous node to current node. */
        previous_node = current_node;

        /* Change to current node to its original next node. */
        current_node = next_node_ptr;
    }

    return previous_node;
}
