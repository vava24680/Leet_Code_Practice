from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(
        self,
        head: Optional[ListNode],
        val: int
    ) -> Optional[ListNode]:
        pseudo_head = ListNode(next=head)
        previous_node = pseudo_head
        current_node = head

        while current_node:
            if val == current_node.val:
                previous_node.next = current_node.next
            else:
                previous_node = current_node

            current_node = current_node.next

        return pseudo_head.next
