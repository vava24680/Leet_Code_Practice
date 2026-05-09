#include <stddef.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
static struct ListNode* mergeTwoSortedLinkedLists(
    struct ListNode *sorted_list_1_head_node_ptr,
    struct ListNode *sorted_list_2_head_node_ptr
) {
    struct ListNode *sorted_list_1_current_node_ptr = (
        sorted_list_1_head_node_ptr
    );
    struct ListNode *sorted_list_2_current_node_ptr = (
        sorted_list_2_head_node_ptr
        );
    struct ListNode *merged_list_head_node_ptr = NULL;
    struct ListNode **next_ptr_ptr = (&merged_list_head_node_ptr);

    while (
        (NULL != sorted_list_1_current_node_ptr)
        &&
        (NULL != sorted_list_2_current_node_ptr)
    ) {
        if (
            (sorted_list_1_current_node_ptr->val)
            <=
            (sorted_list_2_current_node_ptr->val)
        ) {
            (*next_ptr_ptr) = sorted_list_1_current_node_ptr;
            next_ptr_ptr = &(sorted_list_1_current_node_ptr->next);
            sorted_list_1_current_node_ptr = (
                sorted_list_1_current_node_ptr->next
            );
        }
        else {
            (*next_ptr_ptr) = sorted_list_2_current_node_ptr;
            next_ptr_ptr = &(sorted_list_2_current_node_ptr->next);
            sorted_list_2_current_node_ptr = (
                sorted_list_2_current_node_ptr->next
            );
        }
    }

    if (NULL != sorted_list_1_current_node_ptr) {
        (*next_ptr_ptr) = sorted_list_1_current_node_ptr;
    }
    else if (NULL != sorted_list_2_current_node_ptr) {
        (*next_ptr_ptr) = sorted_list_2_current_node_ptr;
    }

    return merged_list_head_node_ptr;
}

struct ListNode* sortList(struct ListNode* head) {
    struct ListNode* slow_pointer = head;
    struct ListNode* fast_pointer = head;
    struct ListNode* previous_node_ptr = NULL;
    struct ListNode* sorted_left_linked_list_head_node_ptr = NULL;
    struct ListNode* sorted_right_linked_list_head_node_ptr = NULL;

    if ((NULL == head) || (NULL == (head->next))) {
        /*
         * If current linked list is empty or it has only one node,
         * it is sorted, just return its head node pointer directly.
         */
        return head;
    }

    /* Use slow and fast pointers to find the middle node. */
    while ((NULL != fast_pointer) && (NULL != (fast_pointer->next))) {
        previous_node_ptr = slow_pointer;
        slow_pointer = (slow_pointer->next);
        fast_pointer = ((fast_pointer->next)->next);
    }

    /*
     * Disconnect the middle node and the node before it, this is to divide
     * the given linked list to two linked lists.
     */
    previous_node_ptr->next = NULL;

    /* Continue to divide these two linked lists to get them sorted. */
    sorted_left_linked_list_head_node_ptr = sortList(head);
    sorted_right_linked_list_head_node_ptr = sortList(slow_pointer);

    /*
     * Merge two sorted linked lists into one sorted linked list
     * and return its head node pointer.
     */
    return mergeTwoSortedLinkedLists(
        sorted_left_linked_list_head_node_ptr,
        sorted_right_linked_list_head_node_ptr
    );
}
