#include <stddef.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int list_a_steps_to_tail_num = 0;
    int list_b_steps_to_tail_num = 0;
    const struct ListNode *list_a_current_node = headA;
    const struct ListNode *list_b_current_node = headB;

    if ((NULL == headA) | (NULL == headB)) {
        return NULL;
    }

    /* Find the distances to the tail node in each list. */
    while (
        (NULL != (list_a_current_node->next))
        ||
        (NULL != (list_b_current_node->next))
    ) {
        if (NULL != (list_a_current_node->next)) {
            ++list_a_steps_to_tail_num;
            list_a_current_node = list_a_current_node->next;
        }

        if (NULL != (list_b_current_node->next)) {
            ++list_b_steps_to_tail_num;
            list_b_current_node = list_b_current_node->next;
        }
    }

    /*
     * If the tail node is not the same, these two linked list won't have
     * intersection.
     */
    if (list_a_current_node != list_b_current_node) {
        return NULL;
    }

    /* Reset current node for two lists. */
    list_a_current_node = headA;
    list_b_current_node = headB;

    /*
     * As the list after the insection node has the same length, we make the
     * searching starting a node that has the same distance to the tail node.
     * In this way, the intersection node can be found during the searching.
     */
    if (list_a_steps_to_tail_num >= list_b_steps_to_tail_num) {
        for (
            int i = 0;
            i < (list_a_steps_to_tail_num - list_b_steps_to_tail_num);
            ++i
        ) {
            list_a_current_node = (list_a_current_node->next);
        }

    }
    else {
        for (
            int i = 0;
            i < (list_b_steps_to_tail_num - list_a_steps_to_tail_num);
            ++i
        ) {
            list_b_current_node = (list_b_current_node->next);
        }
    }

    /*
     * Find intersection node by traversing next node in each iteration.
     * If the current node reference are the same for two lists,
     * the intersection node is found.
     */
    while (list_a_current_node != list_b_current_node) {
        list_a_current_node = (list_a_current_node->next);
        list_b_current_node = (list_b_current_node->next);
    }

    return list_a_current_node;
}
