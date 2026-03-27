#include <stddef.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    const struct ListNode *slow_pointer = head;
    const struct ListNode *fast_pointer = head;

    while ((fast_pointer) && (fast_pointer->next)) {
        slow_pointer = slow_pointer->next;
        fast_pointer = (fast_pointer->next)->next;

        if (slow_pointer == fast_pointer) {
            /*
             * After finding a circle, make slow pointer to head node and make
             * both the slow and fast pointers advance one step each time until
             * two pointers are the same. Now both the slow and fast pointers
             * are the start node of the found circle in the given linked list.
             */
            slow_pointer = head;

            while (slow_pointer != fast_pointer) {
                slow_pointer = slow_pointer->next;
                fast_pointer = fast_pointer->next;
            }

            return slow_pointer;
        }
    }

    return NULL;
}
