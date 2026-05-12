from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if (not head) or (not (head.next)):
            # An empty linked list or an linked list with only one node is
            # considered sorted, return head node directly.
            return head

        sorted_linked_list_dummy_head_node = ListNode(next=head)
        current_node = (head.next)

        # Disconnect the sorted part and the other part.
        (head.next) = None

        while current_node:
            # Backup original next node.
            original_next_node = (current_node.next)
            previous_node = sorted_linked_list_dummy_head_node
            checked_node = (sorted_linked_list_dummy_head_node.next)

            # Find a proper insertion location for current node.
            while checked_node and ((current_node.val) > (checked_node.val)):
                previous_node = checked_node
                checked_node = (checked_node.next)

            # Insert current node to that proper insertion location and link
            # it with its new previous node and new next node.
            (previous_node.next) = current_node
            (current_node.next) = checked_node

            # Go to original next node for next round.
            current_node = original_next_node

        return (sorted_linked_list_dummy_head_node.next)
