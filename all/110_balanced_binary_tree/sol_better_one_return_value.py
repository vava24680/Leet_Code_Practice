from typing import Optional


UNBALANCED_SPECIAL_RETURN_VALUE = -2


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def computeHeight(root: Optional[TreeNode]) -> int:
            if not root:
                # Empty binary tree has height -1.
                return -1

            left_subtree_height = computeHeight(root.left)

            if UNBALANCED_SPECIAL_RETURN_VALUE == left_subtree_height:
                return UNBALANCED_SPECIAL_RETURN_VALUE

            right_subtree_height = computeHeight(root.right)

            if UNBALANCED_SPECIAL_RETURN_VALUE == right_subtree_height:
                return UNBALANCED_SPECIAL_RETURN_VALUE

            if abs(left_subtree_height - right_subtree_height) > 1:
                return UNBALANCED_SPECIAL_RETURN_VALUE

            return max(left_subtree_height, right_subtree_height) + 1

        height = computeHeight(root)

        return UNBALANCED_SPECIAL_RETURN_VALUE != height
