#include <stddef.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    /*
     * Use slow and fast pointers to find the middle node of the given linked
     * list.
     *
     * Slow pointer advances one node each time.
     * Fast pointer advances two nodes each time.
     *
     * When fast pointer is NULL or its next is NULL, the slow pointer will
     * point to the middle node.
     */
    struct ListNode* slow_pointer = head;
    struct ListNode* fast_pointer = head;

    while ((NULL != fast_pointer) && (NULL != (fast_pointer->next))) {
        slow_pointer = slow_pointer->next;
        fast_pointer = (fast_pointer->next)->next;
    }

    return slow_pointer;
}
