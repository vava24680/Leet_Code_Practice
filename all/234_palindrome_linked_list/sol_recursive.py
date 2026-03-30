from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        left_node = head

        def checkPalindromeRecursively(
            current_node: Optional[ListNode]
        ) -> bool:
            if not current_node:
                return True

            if not checkPalindromeRecursively(current_node.next):
                return False

            nonlocal left_node

            result = ((current_node.val) == (left_node.val))

            left_node = left_node.next

            return result

        return checkPalindromeRecursively(head)
