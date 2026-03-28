from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseListRecursively(
        self,
        previou_node: Optional[ListNode],
        current_node: Optional[ListNode]
    ) -> Optional[ListNode]:
        # Change each current node's next pointer to point to the previous node.
        # Termination condition: when current node is None, it means we have
        # traversed the whole linked list, and now previous node will be the
        # new head of the reversed linked list.
        if not current_node:
            return previou_node

        # Save the next node pointer.
        next_node = current_node.next

        # Change current node's next pointer to point to the previou node.
        current_node.next = previou_node

        return self.reverseListRecursively(current_node, next_node)

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return self.reverseListRecursively(None, head)
