from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
def reverseLinkedList(head: Optional[ListNode]) -> Optional[ListNode]:
    previous_node = None
    current_node = head
    next_node = None

    while current_node:
        next_node = (current_node.next)
        current_node.next = previous_node
        previous_node = current_node
        current_node = next_node

    return previous_node


class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow_pointer = head
        fast_pointer = head

        while fast_pointer and (fast_pointer.next):
            slow_pointer = (slow_pointer.next)
            fast_pointer = ((fast_pointer.next).next)

        left_part_list_current_node = head
        right_part_list_current_node = reverseLinkedList(slow_pointer)

        while right_part_list_current_node:
            if (
                (left_part_list_current_node.val)
                !=
                (right_part_list_current_node.val)
            ):
                return False

            left_part_list_current_node = (left_part_list_current_node.next)
            right_part_list_current_node = (right_part_list_current_node.next)

        return True
