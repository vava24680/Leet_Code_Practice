#include <stddef.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    /*
     * Suppose we have two linked list: a, b.
     * The length of a, b is m, n.
     * The length of intersected list is k, and m >= k, n >= k.
     *
     * If two singly linked list has a intersection node, the length after the
     * intersection node of a list is as same as the other one.
     *
     * If we chain list a and list b with a pseudo node NULL to two lists:
     * list (a + b) and list(b + a).
     * We use two pointers to traverse the two chained lists. If we can find
     * that current two nodes' references (addresses) are the same, it means
     * we find the intersection node. The termination condtion is two current
     * nodes' references (addresses) are the same.
     *
     * The reason why we need the pseudo node NULL is because if we just check
     * if current node is the tail node of list a or list b and change it the
     * other list's head, we will not be able to break the loop if there is no
     * intersection node in the given two lists because it's impossible that
     * list a current node and list b current node are the same if they have
     * different length.
     *
     * If real programming, we won't create that psuedo node NULL, we just
     * let current node becomes NULL after tail node, and if it is, change
     * to the other list's head.
     *
     * The reason why it works is because that the two chained lists has the
     * same length (m + n + 1) and the length of a list after the
     * intersection node is as same as the other one, and we use two lists
     * having the same length, we must have the intersection node found after
     * (m + n + 1 - k) steps.
     */
    struct ListNode *list_ab_current_node = headA;
    struct ListNode *list_ba_current_node = headB;

    if ((NULL == headA) || (NULL == headB)) {
        return NULL;
    }

    while (list_ab_current_node != list_ba_current_node) {
        if (NULL == list_ab_current_node) {
            list_ab_current_node = headB;
        }
        else {
            list_ab_current_node = (list_ab_current_node->next);
        }

        if (NULL == list_ba_current_node) {
            list_ba_current_node = headA;
        }
        else {
            list_ba_current_node = (list_ba_current_node->next);
        }
    }

    return  list_ab_current_node;
}
