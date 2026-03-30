from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Use slow and fast pointers to find the middle node of the given
        # linked list.
        #
        # Slow pointer advances one node each time.
        # Fast pointer advances two nodes each time.
        #
        # When fast pointer is NULL or its next is NULL, the slow pointer will
        # point to the middle node.
        slow_pointer = head
        fast_pointer = head

        while fast_pointer and fast_pointer.next:
            slow_pointer = slow_pointer.next
            fast_pointer = fast_pointer.next.next

        return slow_pointer
