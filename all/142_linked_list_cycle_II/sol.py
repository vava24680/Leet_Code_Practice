from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow_pointer = head
        fast_pointer = head

        while fast_pointer and (fast_pointer.next):
            slow_pointer = slow_pointer.next
            fast_pointer = fast_pointer.next.next

            if slow_pointer == fast_pointer:
                # After finding a circle, make slow pointer to head node and
                # make both the slow and fast pointers advance one step
                # each time until two pointers are the same.
                # Now both the slow and fast pointers points to the start node
                # of the found circle in the given linked list.
                slow_pointer = head

                while slow_pointer != fast_pointer:
                    slow_pointer = slow_pointer.next
                    fast_pointer = fast_pointer.next

                return slow_pointer

        return None
