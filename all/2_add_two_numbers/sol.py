from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(
        self,
        l1: Optional[ListNode],
        l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        answer_number_linked_list_dummy_head = ListNode()
        current_tail_node = answer_number_linked_list_dummy_head
        carry_value = 0

        while l1 or l2:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0

            carry_value, current_value = divmod(v1 + v2 + carry_value, 10)
            current_node = ListNode(current_value)
            current_tail_node.next = current_node
            current_tail_node = current_node

            if l1:
                l1 = l1.next

            if l2:
                l2 = l2.next

        if carry_value:
            current_node = ListNode(carry_value)
            current_tail_node.next = current_node
            current_tail_node = current_node

        return answer_number_linked_list_dummy_head.next
