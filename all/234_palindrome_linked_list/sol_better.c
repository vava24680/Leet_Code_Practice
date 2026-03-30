#include <stdbool.h>
#include <stddef.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseLinkedList(struct ListNode * const head) {
    struct ListNode *current_node = head;
    struct ListNode *previous_node = NULL;
    struct ListNode *next_node_ptr = NULL;

    while (NULL != current_node) {
        next_node_ptr = (current_node->next);
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node_ptr;
    }

    return previous_node;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode *left_part_list_current_node_ptr = NULL;
    struct ListNode *right_part_list_current_node_ptr = NULL;
    struct ListNode *slow_ptr = head;
    struct ListNode *fast_ptr = head;

    /* Find the middle node in the linked list. */
    while (
        (NULL != (fast_ptr->next))
        &&
        (NULL != ((fast_ptr->next)->next))
    ) {
        slow_ptr = (slow_ptr->next);
        fast_ptr = ((fast_ptr->next)->next);
    }

    /* Reverse the the linked list at the right hand side of the middle node. */
    right_part_list_current_node_ptr = reverseLinkedList(slow_ptr->next);
    left_part_list_current_node_ptr = head;

    while (NULL != right_part_list_current_node_ptr) {
        if (
            (left_part_list_current_node_ptr->val)
            !=
            (right_part_list_current_node_ptr->val)
        ) {
            return false;
        }

        left_part_list_current_node_ptr = (
            left_part_list_current_node_ptr->next
        );
        right_part_list_current_node_ptr = (
            right_part_list_current_node_ptr->next
        );
    }

    return true;
}
