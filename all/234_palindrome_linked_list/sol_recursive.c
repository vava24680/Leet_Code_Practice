#include <stdbool.h>
#include <stddef.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool checkPalindromeRecursively(
    struct ListNode **left_node_ptr_ptr,
    const struct ListNode * const current_node_ptr
) {
    if (NULL == current_node_ptr) {
        return true;
    }

    if (
        !checkPalindromeRecursively(
            left_node_ptr_ptr,
            current_node_ptr->next
        )
    ) {
        return false;
    }

    bool current_result = (
        (current_node_ptr->val) == ((*left_node_ptr_ptr)->val)
    );

    (*left_node_ptr_ptr) = ((*left_node_ptr_ptr)->next);

    return current_result;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode * left_node_ptr = head;

    return checkPalindromeRecursively(&left_node_ptr, head);
}
