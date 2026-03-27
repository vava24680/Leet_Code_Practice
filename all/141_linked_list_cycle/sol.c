#include <stdbool.h>
#include <stddef.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    /*
     * Use slow and fast these two pointers to traverse linked list.
     * Slow pointer traverse to next node in each iteration and fast pointer
     * traverse to next 2 node in each iteration.
     * If there is a ring in linked list, fast pointer will eventually catch up
     * the slow pointer.
     *
     * Suppose slow pointer currently is at the node where the circle starts.
     * Fast pointer must be somewhere in the circle. Assume slow pointer is
     * away from the starting node a steps, and fast pointer has k steps to
     * catch up slow pointer. After one iteration, the fast distance of the
     * slow pointer and fast pointer decrements by 1, which means fast pointer
     * has (k - 1) steps to catch up slow pointer. From this, we can conclude
     * that after k iteration, fast pointer will catch slow pointer.
     * As this requires (a + k) iteration, and (a + k) must equal to or less than
     * n (since slow pointer and fast pointer are all in the linkes list, (a + k)
     * is never greater than n), it means the time complexity will be O(n).
     */
    const struct ListNode * slow_pointer = head;
    const struct ListNode * fast_pointer = head;

    /*
     * As fast pointer will advance two nodes, we need to make sure both
     * fast pointer and its next node are not NULL.
     */
    while (
        (NULL != slow_pointer)
        &&
        (NULL != fast_pointer)
        &&
        (NULL != (fast_pointer->next))
    ) {
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next->next;

        if (slow_pointer == fast_pointer) {
            return true;
        }
    }

    return false;
}
