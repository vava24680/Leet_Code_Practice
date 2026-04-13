from typing import Optional


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def invertTreeByPostorderTraversal(root: Optional[TreeNode]) -> None:
            if not root:
                return

            # Invert the left subtree and the right subtree first.
            invertTreeByPostorderTraversal(root.left)
            invertTreeByPostorderTraversal(root.right)

            # Swap the left subtree and the right subtree.
            (root.left), (root.right) = (root.right), (root.left)

        invertTreeByPostorderTraversal(root)

        return root
