from typing import Optional


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None

        nodes_list = list()
        nodes_stack = list()
        current_node = root

        while current_node or nodes_stack:
            if current_node:
                nodes_stack.append(current_node)
                current_node = current_node.left
            else:
                current_node = nodes_stack.pop()
                nodes_list.append(current_node)
                current_node = current_node.right

        # Use the origianl nodes space to construct a balanced binary search
        # tree.
        def buildBalancedBinarySearchTree(
            left_index: int,
            right_index: int
        ) -> Optional[TreeNode]:
            if left_index > right_index:
                return None

            middle_index = left_index + ((right_index - left_index) >> 1)
            current_root = nodes_list[middle_index]
            current_root.left = buildBalancedBinarySearchTree(
                left_index,
                middle_index - 1
            )
            current_root.right = buildBalancedBinarySearchTree(
                middle_index + 1,
                right_index
            )

            return current_root

        return buildBalancedBinarySearchTree(0, len(nodes_list) - 1)
