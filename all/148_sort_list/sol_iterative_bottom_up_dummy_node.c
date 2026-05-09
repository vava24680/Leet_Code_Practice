#include <stddef.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

static int computeLinkedListNodesCount(const struct ListNode *head_node_ptr) {
    const struct ListNode *current_node_ptr = head_node_ptr;

    int nodes_count = 0;

    while (NULL != current_node_ptr) {
        ++nodes_count;

        current_node_ptr = (current_node_ptr->next);
    }

    return nodes_count;
}

static void mergeTwoSortedLinkedLists(
    struct ListNode *sorted_linked_list_1_head_node_ptr,
    struct ListNode *sorted_linked_list_2_head_node_ptr,
    struct ListNode **merged_sorted_linked_list_head_node_ptr_ptr,
    struct ListNode **merged_sorted_linked_list_tail_node_ptr_ptr
) {
    struct ListNode dummy_node = {
        .next = NULL
    };
    struct ListNode *sorted_linked_list_1_current_node_ptr = (
        sorted_linked_list_1_head_node_ptr
    );
    struct ListNode *sorted_linked_list_2_current_node_ptr = (
        sorted_linked_list_2_head_node_ptr
    );
    struct ListNode *merged_sorted_linked_list_tail_node_ptr = (&dummy_node);

    while (
        (NULL != sorted_linked_list_1_current_node_ptr)
        &&
        (NULL != sorted_linked_list_2_current_node_ptr)
    ) {
        if (
            (sorted_linked_list_1_current_node_ptr->val)
            <=
            (sorted_linked_list_2_current_node_ptr->val)
        ) {
            (merged_sorted_linked_list_tail_node_ptr->next) = (
                sorted_linked_list_1_current_node_ptr
            );
            sorted_linked_list_1_current_node_ptr = (
                sorted_linked_list_1_current_node_ptr->next
            );
        }
        else {
            (merged_sorted_linked_list_tail_node_ptr->next) = (
                sorted_linked_list_2_current_node_ptr
            );
            sorted_linked_list_2_current_node_ptr = (
                sorted_linked_list_2_current_node_ptr->next
            );
        }

        merged_sorted_linked_list_tail_node_ptr = (
            merged_sorted_linked_list_tail_node_ptr->next
        );
    }

    if (NULL != sorted_linked_list_1_current_node_ptr) {
        (merged_sorted_linked_list_tail_node_ptr->next) = (
            sorted_linked_list_1_current_node_ptr
        );
    }
    else if (NULL != sorted_linked_list_2_current_node_ptr) {
        (merged_sorted_linked_list_tail_node_ptr->next) = (
            sorted_linked_list_2_current_node_ptr
        );
    }

    /* Get merged sorted linked list tail node. */
    while (NULL != (merged_sorted_linked_list_tail_node_ptr->next)) {
        merged_sorted_linked_list_tail_node_ptr = (
            merged_sorted_linked_list_tail_node_ptr->next
        );
    }

    (*merged_sorted_linked_list_head_node_ptr_ptr) = (dummy_node.next);
    (*merged_sorted_linked_list_tail_node_ptr_ptr) = (
        merged_sorted_linked_list_tail_node_ptr
    );
}

struct ListNode* sortList(struct ListNode* head) {
    const int total_nodes_count = computeLinkedListNodesCount(head);

    if (total_nodes_count <= 1) {
        /*
         * If the given linked list is empty or only has one node, it is
         * considered sorted, return the head node directly.
         */
        return head;
    }

    int current_traversed_nodes_count = 0;
    struct ListNode all_merged_sorted_linked_list_dummy_head_node = {
        .next = head
    };

    struct ListNode *previous_node_ptr = NULL;
    struct ListNode *rest_linked_list_head_node_ptr = NULL;
    struct ListNode *sorted_linked_list_1_head_node_ptr = NULL;
    struct ListNode *sorted_linked_list_2_head_node_ptr = NULL;
    struct ListNode *merged_sorted_linked_list_head_node_ptr = NULL;
    struct ListNode *merged_sorted_linked_list_tail_node_ptr = NULL;
    struct ListNode *all_merged_sorted_linked_list_tail_node_ptr = NULL;

    for (
        int sorted_linked_list_nodes_count = 1;
        sorted_linked_list_nodes_count < total_nodes_count;
        sorted_linked_list_nodes_count <<= 1
    ) {
        /* Get the linked list that we need to apply merge sort. */
        rest_linked_list_head_node_ptr = (
            all_merged_sorted_linked_list_dummy_head_node.next
        );

        /*
         * Make the linked list that links all the merged sorted linked lists
         * during iterative merge sort procedure empty.
         */
        (all_merged_sorted_linked_list_dummy_head_node.next) = NULL;

        /*
         * Reset the tail node of the linked list that links all the merged
         * sorted linked lists during the iterative merge procedure to the
         * dummy head node.
         */
        all_merged_sorted_linked_list_tail_node_ptr = (
            &all_merged_sorted_linked_list_dummy_head_node
        );

        while (rest_linked_list_head_node_ptr) {
            /* Find two sorted linked lists with same nodes count. */

            /* Get the first sorted linked list. */
            sorted_linked_list_1_head_node_ptr = rest_linked_list_head_node_ptr;

            for (
                int current_traversed_nodes_count = 0;
                (
                    rest_linked_list_head_node_ptr
                    &&
                    (
                        current_traversed_nodes_count
                        <
                        sorted_linked_list_nodes_count
                    )
                );
                ++current_traversed_nodes_count
            ) {
                previous_node_ptr = rest_linked_list_head_node_ptr;
                rest_linked_list_head_node_ptr = (
                    rest_linked_list_head_node_ptr->next
                );
            }

            /*
             * Disconnect the first sorted linked list and the rest linked
             * list.
             */
            previous_node_ptr->next = NULL;

            /* Get the second sorted linked list. */
            sorted_linked_list_2_head_node_ptr = rest_linked_list_head_node_ptr;
            previous_node_ptr = NULL;

            for (
                int current_traversed_nodes_count = 0;
                (
                    rest_linked_list_head_node_ptr
                    &&
                    (
                        current_traversed_nodes_count
                        <
                        sorted_linked_list_nodes_count
                    )
                );
                ++current_traversed_nodes_count
            ) {
                previous_node_ptr = rest_linked_list_head_node_ptr;
                rest_linked_list_head_node_ptr = (
                    rest_linked_list_head_node_ptr->next
                );
            }

            /*
             * Disconnect the second sorted linked list and the rest linked
             * list.
             *
             * Second sorted linked list does not always exist, so we need the
             * following check.
             */
            if (previous_node_ptr) {
                previous_node_ptr->next = NULL;
            }

            /*
             * Merge two sorted linked lists and get merged sorted linked
             * list head node pointer and tail node pointer.
             */
            mergeTwoSortedLinkedLists(
                sorted_linked_list_1_head_node_ptr,
                sorted_linked_list_2_head_node_ptr,
                &merged_sorted_linked_list_head_node_ptr,
                &merged_sorted_linked_list_tail_node_ptr
            );

            /*
             * Add current merged sorted linked list to the end of the
             * linked list that links all merged sorted linked list during the
             * iterative merge sort procedure.
             */
            (all_merged_sorted_linked_list_tail_node_ptr->next) = (
                merged_sorted_linked_list_head_node_ptr
            );

            /*
             * Update the tail node of the linked list that links all merged
             * sorted linked list during the iterative merge sort procedure
             * to the tail node of the current sorted linked list.
             */
            all_merged_sorted_linked_list_tail_node_ptr = (
                merged_sorted_linked_list_tail_node_ptr
            );
        }
    }

    /*
     * At the end of iterative merge sort procedure, there will be only one
     * merged sorted linked list, the node after its dummy head node is the head
     * node of the sorted linked list.
     */
    return (all_merged_sorted_linked_list_dummy_head_node.next);
}
