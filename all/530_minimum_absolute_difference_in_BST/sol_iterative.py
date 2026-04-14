from typing import Optional


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        nodes_stack = list()
        previous_traversed_node = None
        current_node = root
        minimum_two_node_values_absolute_difference = float('inf')

        while current_node or nodes_stack:
            if current_node:
                nodes_stack.append(current_node)

                # Traverse left subtree first.
                current_node = current_node.left
            else:
                # There is no more left subtree can be traversed, traverse
                # root node poped from the nodes stack.
                current_node = nodes_stack.pop()

                # If previous traversed node is not None, compute the absolute
                # difference between the current traversed node and the previous
                # traversed node and update the global recorded one if needed.
                if previous_traversed_node is not None:
                    minimum_two_node_values_absolute_difference = min(
                        minimum_two_node_values_absolute_difference,
                        (current_node.val) - (previous_traversed_node.val)
                    )

                # Update previous traversed node as current node.
                previous_traversed_node = current_node

                # After traversing root node, change to traverse right subtree.
                current_node = current_node.right

        return minimum_two_node_values_absolute_difference
