#include <stddef.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* list1_current_node_ptr = list1;
    struct ListNode* list2_current_node_ptr = list2;
    struct ListNode* merged_list_head_node_ptr = NULL;
    struct ListNode** next_ptr_ptr = &merged_list_head_node_ptr;

    while (
        (NULL != list1_current_node_ptr)
        &&
        (NULL != list2_current_node_ptr)
    ) {
        if ((list1_current_node_ptr->val) <= (list2_current_node_ptr->val)) {
            /*
             * Value in the current node in the list 1 is smaller than or equal
             * to the value in the current node in the list 2, we need to add
             * current list 1 head to the merged list.
             */
            (*next_ptr_ptr) = list1_current_node_ptr;
            next_ptr_ptr = (&(list1_current_node_ptr->next));
            list1_current_node_ptr = (list1_current_node_ptr->next);
        }
        else {
            /*
             * Value in the current node in the list 1 is greater than the value
             * in the current node in the list 2, we need to add current list 2
             * head to the merged list.
             */
            (*next_ptr_ptr) = list2_current_node_ptr;
            next_ptr_ptr = (&(list2_current_node_ptr->next));
            list2_current_node_ptr = (list2_current_node_ptr->next);
        }
    }

    if (NULL != list1_current_node_ptr) {
        /*
         * If list 1 still has some nodes, add the whole list 1
         * to the merged list.
         */
        (*next_ptr_ptr) = list1_current_node_ptr;
    }
    else {
        /*
         * If list 2 still has some nodes, add the whole list 2
         * to the merged list.
         */
        (*next_ptr_ptr) = list2_current_node_ptr;
    }

    return merged_list_head_node_ptr;
}
