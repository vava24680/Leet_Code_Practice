from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        current_node = head
        previous_node = None
        next_node = None

        while current_node:
            # Save the next node pointer.
            next_node = current_node.next

            # Make current node's next pointer to point to the previous node.
            current_node.next = previous_node

            # Change previous node to current node.
            previous_node = current_node

            # Change current node to its original next node.
            current_node = next_node

        return previous_node
