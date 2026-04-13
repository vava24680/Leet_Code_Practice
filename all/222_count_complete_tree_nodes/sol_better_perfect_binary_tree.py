from typing import Optional


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        leftmost_depth = 0
        rightmost_depth = 0

        current_node = root

        while (current_node.left):
            # Count the depth from the root node to the leftmost leaf node.
            leftmost_depth += 1

            current_node = (current_node.left)

        current_node = root

        while (current_node.right):
            # Count the depth from the root node to the rightmost leaf node.
            rightmost_depth += 1

            current_node = (current_node.right)

        if leftmost_depth != rightmost_depth:
            return (1 + (self.countNodes(root.left)) + (self.countNodes(root.right)))

        # Current binary tree is a perfect binary tree, number of nodes in the
        # current binary tree is two to the power of (tree depth plus 1) and
        # then minus - 1.
        return ((1 << (leftmost_depth + 1)) - 1)
