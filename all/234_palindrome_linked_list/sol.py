from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        values_list = list()
        current_node = head

        while current_node:
            values_list.append(current_node.val)

            current_node = (current_node.next)

        values_list_length = len(values_list)

        for i in range(values_list_length >> 1):
            if (values_list[i]) != (values_list[values_list_length - 1 - i]):
                return False

        return True
