/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode pseudo_node = {
        .val = 0,
        .next = head,
    };
    struct ListNode *previous_node = &pseudo_node;
    struct ListNode *current_node = head;

    while (current_node) {
        if (val == (current_node->val)) {
            previous_node->next = current_node->next;
        }
        else {
            previous_node = current_node;
        }

        current_node = current_node->next;
    }

    return pseudo_node.next;
}
