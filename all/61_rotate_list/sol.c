#include <stddef.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (NULL == head) {
        return NULL;
    }

    struct ListNode *old_tail_node_ptr = NULL;
    struct ListNode *new_head_node_ptr = head;
    struct ListNode *current_node_ptr = head;
    struct ListNode *new_tail_node_ptr = NULL;

    int nodes_count = 0;
    int actual_right_shifts_count = 0;

    while (NULL != current_node_ptr) {
        ++nodes_count;
        old_tail_node_ptr = current_node_ptr;
        current_node_ptr = (current_node_ptr->next);
    }

    actual_right_shifts_count = (k % nodes_count);

    if (0 == actual_right_shifts_count) {
        /*
         * If actual right shifts count is 0, the new head will be as same as
         * the old head, return old head directly.
         */
        return head;
    }

    /* Link the old tail node and old head node together. */
    (old_tail_node_ptr->next) = head;

    /* Find the new head node and new tail node. */
    for (int i = 0; i < (nodes_count - actual_right_shifts_count); ++i) {
        new_tail_node_ptr = new_head_node_ptr;
        new_head_node_ptr = (new_head_node_ptr->next);
    }

    /* Disconnect the new tail node and the new head node. */
    (new_tail_node_ptr->next) = NULL;

    return new_head_node_ptr;
}
