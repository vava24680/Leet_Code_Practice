from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def computeLinkedListNodesCount(self, head_node: Optional[ListNode]) -> int:
        current_node = head_node
        nodes_count = 0

        while current_node:
            nodes_count += 1
            current_node = (current_node.next)

        return nodes_count

    def mergeTwoSortedLinkedLists(
        self,
        list_1_head_node: Optional[ListNode],
        list_2_head_node: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy_head_node = ListNode()
        merged_sorted_linked_list_tail_node = dummy_head_node
        list_1_current_node = list_1_head_node
        list_2_current_node = list_2_head_node

        while list_1_current_node and list_2_current_node:
            if (list_1_current_node.val) <= (list_2_current_node.val):
                merged_sorted_linked_list_tail_node.next = list_1_current_node
                merged_sorted_linked_list_tail_node = list_1_current_node
                list_1_current_node = (list_1_current_node.next)
            else:
                merged_sorted_linked_list_tail_node.next = list_2_current_node
                merged_sorted_linked_list_tail_node = list_2_current_node
                list_2_current_node = (list_2_current_node.next)

        if list_1_current_node:
            merged_sorted_linked_list_tail_node.next = list_1_current_node
        elif list_2_current_node:
            merged_sorted_linked_list_tail_node.next = list_2_current_node

        while (merged_sorted_linked_list_tail_node.next):
            # Get the merged linked list tail node.
            merged_sorted_linked_list_tail_node = (
                merged_sorted_linked_list_tail_node.next
            )

        return (dummy_head_node.next, merged_sorted_linked_list_tail_node)

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        nodes_count = self.computeLinkedListNodesCount(head)

        if nodes_count <= 1:
            # If the given linked list is empty or only has one node,
            # it is considered sorted, return the head node directly.
            return head

        # This linked list has a dummy head and it links all the sorted linked
        # lists during the following iterative merge sort procedure.
        # It is used as the extra array when implementating merge sort on an
        # array.
        all_merged_sorted_linked_list_dummy_head_node = ListNode(next=head)
        sorted_linked_list_nodes_count = 1

        while sorted_linked_list_nodes_count < nodes_count:
            # Get the linked list that we need to apply merge sort.
            rest_linked_list_head_node = (
                all_merged_sorted_linked_list_dummy_head_node.next
            )

            # Make the linked list that links all the sorted linked lists during
            # iterative merge sort procedure empty.
            all_merged_sorted_linked_list_dummy_head_node.next = None

            # Reset the tail node of the linked list that links all the sorted
            # linked list during iterative merge sort procedure.
            all_merged_sorted_linked_list_tail_node = (
                all_merged_sorted_linked_list_dummy_head_node
            )

            while rest_linked_list_head_node:
                # Find two sorted linked lists with same nodes count.
                sorted_linked_list_1_head_node = rest_linked_list_head_node
                current_traversed_nodes_count = 0

                # Get first sorted linked list.
                while (
                    rest_linked_list_head_node
                    and
                    (
                        current_traversed_nodes_count
                        <
                        sorted_linked_list_nodes_count
                    )
                ):
                    previous_node = rest_linked_list_head_node
                    current_traversed_nodes_count += 1
                    rest_linked_list_head_node = (
                        rest_linked_list_head_node.next
                    )

                # Disconnect the first sorted linked list and the rest linked list.
                previous_node.next = None

                current_traversed_nodes_count = 0
                sorted_linked_list_2_head_node = rest_linked_list_head_node
                previous_node = None

                # Get second sorted linked list.
                while (
                    rest_linked_list_head_node
                    and
                    (
                        current_traversed_nodes_count
                        <
                        sorted_linked_list_nodes_count
                    )
                ):
                    previous_node = rest_linked_list_head_node
                    current_traversed_nodes_count += 1
                    rest_linked_list_head_node = (
                        rest_linked_list_head_node.next
                    )

                # Disconnect the second sorted linked list and the rest linked
                # list.
                # Second sorted linked list does not always exist, so we need to
                # add the following check.
                if previous_node:
                    previous_node.next = None

                # Merge the two sorted linked list and get merged linked list
                # head node nad tail node.
                (
                    merged_sorted_linked_list_head_node,
                    merged_sorted_linked_list_tail_node
                ) = self.mergeTwoSortedLinkedLists(
                    sorted_linked_list_1_head_node,
                    sorted_linked_list_2_head_node
                )

                # Add current merged sorted linked list to the end of the
                # linked list that links all merged sorted linked list in the
                # iterative merge sort procedure.
                all_merged_sorted_linked_list_tail_node.next = (
                    merged_sorted_linked_list_head_node
                )

                # Change the tail node of the linked list that links all merged
                # sorted linked list in the iterative merge sort procedure to the
                # tail node of current merged sorted linked list.
                all_merged_sorted_linked_list_tail_node = (
                    merged_sorted_linked_list_tail_node
                )

            sorted_linked_list_nodes_count <<= 1

        # At the end of iterative merge sort procedure, there will be only one
        # merged sorted linked list, its head the head node the sorted linked
        # list.
        return (all_merged_sorted_linked_list_dummy_head_node.next)
