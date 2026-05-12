#include <stddef.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if ((NULL == head) || (NULL == (head->next))) {
        /*
         * An empty linked list or an linked list with only one node is
         * considered sorted, return head pointer directly.
         */
        return head;
    }

    struct ListNode *current_node_ptr = (head->next);
    struct ListNode *checked_node_ptr = NULL;
    struct ListNode *sorted_linked_list_head_node_ptr = head;
    struct ListNode *original_next_node_ptr = NULL;

    /*
     * This is a pointer that points to the next pointer of previous
     * node. It's used when find a proper insetion location for a node.
     * This is usage of indirect pointer.
     */
    struct ListNode **previous_node_next_ptr_ptr = NULL;

    /* Disconnect the sorted part and the other part. */
    (head->next) = NULL;

    while (current_node_ptr) {
        /* Backup original next node pointer. */
        original_next_node_ptr = (current_node_ptr->next);
        checked_node_ptr = sorted_linked_list_head_node_ptr;
        previous_node_next_ptr_ptr = (&sorted_linked_list_head_node_ptr);

        /* Find a proper insertion location for current node. */
        while (
            (NULL != checked_node_ptr)
            &&
            ((current_node_ptr->val) > (checked_node_ptr->val))
        ) {
            previous_node_next_ptr_ptr = (&(checked_node_ptr->next));
            checked_node_ptr = (checked_node_ptr->next);
        }

        /*
         * Insert current node to that proper insertion location and link it
         * with its new previous node and new next node.
         */
        (*previous_node_next_ptr_ptr) = current_node_ptr;
        (current_node_ptr->next) = checked_node_ptr;

        /* Go to original next node for next round. */
        current_node_ptr = original_next_node_ptr;
    }

    return sorted_linked_list_head_node_ptr;
}
