from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(
        self,
        head: Optional[ListNode], k: int
    ) -> Optional[ListNode]:
        if not head:
            return None

        nodes_count = 0
        current_node = head
        old_tail_node = head

        # Compute the nodes count in the given linked list.
        while current_node:
            nodes_count += 1
            old_tail_node = current_node
            current_node = (current_node.next)

        actual_right_shifts_count = (k % nodes_count)

        if 0 == actual_right_shifts_count:
            # If actual right shifts count is 0, the new head will be as same as
            # the old head, return old head directly.
            return head

        # Link the old tail node and old head node together.
        old_tail_node.next = head

        new_head_node = head

        # Find the new head node and new tail node.
        for _i in range(nodes_count - actual_right_shifts_count):
            new_tail_node = new_head_node
            new_head_node = (new_head_node.next)

        # Make new tail node link to None.
        new_tail_node.next = None

        return new_head_node
