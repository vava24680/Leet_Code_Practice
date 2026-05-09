from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
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

        return (dummy_head_node.next)

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if (not head) or (not (head.next)):
            # If the given linked list is empty or it has only one node,
            # it is considered sorted, return its head node directly.
            return head

        slow_pointer = head
        fast_pointer = head

        # Use slow and fast pointer to find the middle node.
        while fast_pointer and (fast_pointer.next):
            previous_node = slow_pointer
            slow_pointer = (slow_pointer.next)
            fast_pointer = ((fast_pointer.next).next)

        # Disconnect the middle node and the node before it to divide the given
        # linked list to two linked lists.
        previous_node.next = None

        # Continue to divide these two linked lists to get them sorted.
        sorted_left_linked_list_head_node = self.sortList(head)
        sorted_right_linked_list_head_node = self.sortList(slow_pointer)

        # Merge two sorted linked lists into one sorted linked list
        # and return its head node.
        return self.mergeTwoSortedLinkedLists(
            sorted_left_linked_list_head_node,
            sorted_right_linked_list_head_node
        )
