from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        values_stack = list()
        current_node = head

        # Push every node's value into values stack.
        while current_node:
            values_stack.append(current_node.val)

            current_node = (current_node.next)

        # Reset current node to head.
        current_node = head

        # Check if the value of the current iterated node is equal to the
        # value poped from stack to check if the given linked list is
        # palindrome.
        while current_node:
            if (current_node.val) != (values_stack.pop()):
                return False

            current_node = (current_node.next)

        return True
