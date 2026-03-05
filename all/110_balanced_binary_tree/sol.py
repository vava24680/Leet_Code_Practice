from typing import Optional, Tuple


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def checkIsBalanced(
            root: Optional[TreeNode]
        ) -> Tuple[bool, int]:
            if not root:
                # Empty binary tree has height -1.
                return (True, -1)

            is_left_subtree_balanced, left_subtree_height = (
                checkIsBalanced(root.left)
            )
            is_right_subtree_balanced, right_subtree_height = (
                checkIsBalanced(root.right)
            )

            is_current_tree_balanced = (
                (is_left_subtree_balanced)
                and
                (is_right_subtree_balanced)
                and
                ((abs(left_subtree_height - right_subtree_height)) <= 1)
            )

            return (
                is_current_tree_balanced,
                max(left_subtree_height, right_subtree_height) + 1
            )

        is_balanced, height = checkIsBalanced(root)

        return is_balanced
