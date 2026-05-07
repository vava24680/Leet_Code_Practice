from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(
        self,
        list1: Optional[ListNode],
        list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        list1_current_node = list1
        list2_current_node = list2
        merged_list_head = ListNode()
        merged_list_current_node = merged_list_head

        while list1_current_node and list2_current_node:
            if (list1_current_node.val) <= (list2_current_node.val):
                # Value in the current node in the list 1 is smaller than
                # or equal to the value in the current node in the list 2,
                # we need to add current list 1 head to the merged list.
                merged_list_current_node.next = list1_current_node
                merged_list_current_node = list1_current_node
                list1_current_node = (list1_current_node.next)
            else:
                # Value in the current node in the list 1 is greater than the
                # value in the current node in the list 2, we need to add
                # current list 2 head to the merged list.
                merged_list_current_node.next = list2_current_node
                merged_list_current_node = list2_current_node
                list2_current_node = (list2_current_node.next)

        if list1_current_node:
            # If list 1 still has some nodes, add the whole list 1
            # to the merged list.
            merged_list_current_node.next = list1_current_node
        else:
            # If list 2 still has some nodes, add the whole list 2
            # to the merged list.
            merged_list_current_node.next = list2_current_node

        return merged_list_head.next
