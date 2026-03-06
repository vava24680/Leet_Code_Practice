#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry_value = 0, v1 = 0, v2 = 0;
    struct ListNode answer_number_linked_list_dummy_head;
    struct ListNode* current_tail_node_ptr = (&answer_number_linked_list_dummy_head);
    struct ListNode* current_node_ptr = NULL;

    while (l1 || l2) {
        if (l1) {
            v1 = (l1->val);
        }
        else {
            v1 = 0;
        }

        if (l2) {
            v2 = (l2->val);
        }
        else {
            v2 = 0;
        }

        current_node_ptr = (struct ListNode*)malloc(sizeof(*current_node_ptr));
        (current_node_ptr->val) = ((v1 + v2 + carry_value) % 10);
        (current_node_ptr->next) = NULL;
        (current_tail_node_ptr->next) = current_node_ptr;
        current_tail_node_ptr = current_node_ptr;
        carry_value = ((v1 + v2 + carry_value) / 10);

        if (l1) {
            l1 = l1->next;
        }

        if (l2) {
            l2 = l2->next;
        }
    }

    if (carry_value) {
        current_node_ptr = (struct ListNode*)malloc(sizeof(*current_node_ptr));
        (current_node_ptr->val) = carry_value;
        (current_node_ptr->next) = NULL;

        (current_tail_node_ptr->next) = current_node_ptr;
        current_tail_node_ptr = current_node_ptr;
    }

    return answer_number_linked_list_dummy_head.next;
}
