from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(
        self,
        headA: ListNode,
        headB: ListNode
    ) -> Optional[ListNode]:
        list_a_node = headA
        list_b_node = headB
        list_a_length = 0
        list_b_length = 0

        if (not list_a_node) or (not list_b_node):
            return False

        # Find the distances to the tail node in each list.
        while list_a_node.next or list_b_node.next:
            if (list_a_node.next):
                list_a_node = (list_a_node.next)
                list_a_length += 1

            if (list_b_node.next):
                list_b_node = (list_b_node.next)
                list_b_length += 1

        if list_a_node is not list_b_node:
            # If tail nodes of the both linked lists are not the same, it means
            # those linked lists does not intersect, just return None.
            return None

        # Reset current node pointers.
        list_a_node = headA
        list_b_node = headB

        # As the list after the insection node has the same length, we make the
        # searching starting a node that has the same distance to the tail node.
        # In this way, the intersection node can be found during the searching.
        if list_a_length >= list_b_length:
            for _ in range(list_a_length - list_b_length):
                list_a_node = (list_a_node.next)
        else:
            for _ in range(list_b_length - list_a_length):
                list_b_node = (list_b_node.next)

        # Find intersection node by traversing next node in each iteration.
        # If the current node reference are the same for two lists,
        # the intersection node is found.
        while list_a_node is not list_b_node:
            list_a_node = (list_a_node.next)
            list_b_node = (list_b_node.next)

        return list_a_node
