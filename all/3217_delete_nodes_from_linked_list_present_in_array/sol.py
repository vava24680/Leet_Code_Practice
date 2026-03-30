from typing import List, Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(
        self,
        nums: List[int],
        head: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy_head_node = ListNode(0, head)
        nums_set = set(nums)
        current_node = head
        previous_node = dummy_head_node

        while current_node:
            if current_node.val in nums_set:
                previous_node.next = current_node.next
            else:
                previous_node = current_node

            current_node = current_node.next

        return dummy_head_node.next
