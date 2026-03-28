/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseListRecursively(
    struct ListNode *previous_node,
    struct ListNode *current_node
) {
    struct ListNode *next_node = NULL;

    /*
     * Recursively change each current node to point to its previous node.
     * Termination condition: when current node is NULL, it means we have
     * traversed the whole linked list, and now the previous node will be the
     * new head.
     */
    if (NULL == current_node) {
        return previous_node;
    }

    /* Save the next node pointer. */
    next_node = (current_node->next);

    /* Change current node's next pointer to point to the previous node. */
    current_node->next = previous_node;

    return reverseListRecursively(current_node, next_node);
}

struct ListNode* reverseList(struct ListNode* head) {
    return reverseListRecursively(NULL, head);
}
